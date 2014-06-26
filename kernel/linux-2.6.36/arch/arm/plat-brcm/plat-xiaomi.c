/*
 * Copyright © 2014 Jack Tan <jiankemeng@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int model_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%s", "R1D");
	return 0;
}

static int reset_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d", 17);
	return 0;
}

static int model_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, model_proc_show, NULL);
}

static int reset_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, reset_proc_show, NULL);
}

static const struct file_operations model_proc_fops = {
	.open = model_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release
};

static const struct file_operations reset_proc_fops = {
	.open = reset_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release
};


static int __init proc_xm_init(void)
{
#ifdef CONFIG_PROC_FS
	struct proc_dir_entry *res;
	struct proc_dir_entry *proc_xm_dir = NULL;

	proc_xm_dir = proc_mkdir("xiaoqiang", NULL);

	res = proc_create("model", 0444, proc_xm_dir,
				&model_proc_fops);
	if (!res)
		return -ENOMEM;

	res = proc_create("reset", 0444, proc_xm_dir,
				&reset_proc_fops);
	if (!res)
		return -ENOMEM;
#endif
	return 0;
}

fs_initcall(proc_xm_init);
