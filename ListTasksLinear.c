#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* This function is called when the module is loaded. */
int entryPoint(void) {
	struct task_struct *task; //Pointer to the task whose info will be printed

	printk(KERN_INFO "Inserting ListTasksLinear\n");	
	
	printk(KERN_INFO "Started listing tasks\n");

	for_each_process(task) { //Loop over the tasks using the macro for_each_process

		/* on each iteration task points to the next task */
		//task->comm is the task' name
		//task->state is the task's state (-1 unrunnable, 0 runnable, >0 stopped)
		//task->pid is the task's process ID
		printk(KERN_INFO "Name: %-20s State: %ld\tProcess ID: %d\n", task->comm, task->state, task->pid);
	}
	
	printk(KERN_INFO "Stopped listing tasks\n");
	return 0;
}

/* This function is called when the module is removed. */
void exitPoint(void) {
	printk(KERN_INFO "Removing ListTasksLinear\n");
}

/* Macros for registering module entry and exit points. */
module_init(entryPoint);
module_exit(exitPoint);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("List tasks linearly");
MODULE_AUTHOR("Youssef Hassan, 900132871");
