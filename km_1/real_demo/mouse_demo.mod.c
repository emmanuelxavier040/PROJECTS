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
	{ 0xd509b00, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xeb9f8fe3, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x27f9f8b3, __VMLINUX_SYMBOL_STR(input_free_device) },
	{ 0xbc099c9f, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xf9c0b663, __VMLINUX_SYMBOL_STR(strlcat) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xff7d35c6, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0x777a111a, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0xd411059e, __VMLINUX_SYMBOL_STR(input_allocate_device) },
	{ 0x215b60b8, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x83b32430, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xaa1f6354, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x4df6b872, __VMLINUX_SYMBOL_STR(input_event) },
	{ 0x90143332, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xab900b1, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x566596ac, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x30b8faf3, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0x127212c7, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v*p*d*dc*dsc*dp*ic03isc01ip02in*");

MODULE_INFO(srcversion, "DD59E5611728B2C7EA79DAC");
