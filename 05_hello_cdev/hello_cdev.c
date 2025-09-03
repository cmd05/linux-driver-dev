#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

int my_init(void);
void my_exit(void);

static int major;
static int minor;

int __init my_init(void) {
    major = register_chrdev(0, "hello_cdev", &fops);

    if(major < 0) {
        printk("hello cdev - error registering chrdev\n");
        return major;
    }

    printk("");

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
MODULE_DESCRIPTION("A sample driver for registering a character device");