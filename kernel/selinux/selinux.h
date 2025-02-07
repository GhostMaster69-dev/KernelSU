#ifndef __KSU_H_SELINUX
#define __KSU_H_SELINUX

#include "linux/types.h"
#include "linux/version.h"

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)) || defined(KSU_COMPAT_HAS_SELINUX_STATE)
#define KSU_COMPAT_USE_SELINUX_STATE
#endif

#define KERNEL_SU_DOMAIN	"u:r:su:s0"
#define INIT_DOMAIN		"u:r:init:s0"

void setup_selinux(const char *);

void setenforce(bool);

bool getenforce();

bool is_ksu_domain();

void apply_kernelsu_rules();

#endif
