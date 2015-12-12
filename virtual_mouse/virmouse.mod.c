#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x53a8e63d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x48bea7ab, __VMLINUX_SYMBOL_STR(platform_device_unregister) },
	{ 0x18851c14, __VMLINUX_SYMBOL_STR(sysfs_remove_group) },
	{ 0x30b8faf3, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0xc5fdef94, __VMLINUX_SYMBOL_STR(call_usermodehelper) },
	{ 0xbc099c9f, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0xd411059e, __VMLINUX_SYMBOL_STR(input_allocate_device) },
	{ 0x9cf067da, __VMLINUX_SYMBOL_STR(sysfs_create_group) },
	{ 0x679fe7c6, __VMLINUX_SYMBOL_STR(platform_device_register_full) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x4df6b872, __VMLINUX_SYMBOL_STR(input_event) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "00402E5F04B40E36885BBF9");