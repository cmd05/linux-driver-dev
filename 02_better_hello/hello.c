#include <linux/module.h>
#include <linux/init.h>

int my_init(void);
void my_exit(void);

int __init my_init(void) {
    printk("hello - Hello, Kernel!\n");
    return 0;
}

void __exit my_exit(void) {
    printk("hello - Goodbye, Kernel!\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("aquila <aquila@mail.me>");
MODULE_DESCRIPTION("A simple hello world Linux Kernel module");