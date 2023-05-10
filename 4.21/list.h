/* SPDX-License-Identifier: GPL-2.0 */
#ifndef LIST_H
#define LIST_H

/*
 * Copied from include/linux/...
 */

#undef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
				container_of-将结构的成员强制转换为包含结构
 * @ptr:        the pointer to the member. 
				指向成员的指针。
 * @type:       the type of the container struct this is embedded in.
				它所嵌入的容器结构的类型。
 * @member:     the name of the member within the struct.
				结构中成员的名称。
 *
 */
#define container_of(ptr, type, member) ({                      \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})


struct list_head {
	struct list_head *next, *prev;
};


#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

/**
 * list_entry - get the struct for this entry
				获取此条目的结构
 * @ptr:	the &struct list_head pointer.
			当前结构题中的list_head指针。
 * @type:	the type of the struct this is embedded in.
			它所嵌入的结构的类型。
 * @member:	the name of the list_head within the struct.
			当前在结构体中list_head的名称。
 */
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * list_for_each_entry	-	iterate over list of given type
			迭代给定类型的列表
 * @pos:	the type * to use as a loop cursor.
			要用作循环光标的类型*。
 * @head:	the head for your list.
			你名单的标题。
 * @member:	the name of the list_head within the struct.
			结构中list_head的名称。
 */
#define list_for_each_entry(pos, head, member)				\
	for (pos = list_entry((head)->next, typeof(*pos), member);	\
	     &pos->member != (head); 	\
	     pos = list_entry(pos->member.next, typeof(*pos), member))

/**
 * list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
			迭代给定类型的列表，以防删除列表条目
 * @pos:	the type * to use as a loop cursor.
			要用作循环光标的类型*。
 * @n:		another type * to use as temporary storage
			另一种类型*用作临时存储器
 * @head:	the head for your list.
			你名单的标题。
 * @member:	the name of the list_head within the struct.
			结构中list_head的名称。
 */
#define list_for_each_entry_safe(pos, n, head, member)			\
	for (pos = list_entry((head)->next, typeof(*pos), member),	\
		n = list_entry(pos->member.next, typeof(*pos), member);	\
	     &pos->member != (head);					\
	     pos = n, n = list_entry(n->member.next, typeof(*n), member))

/**
 * list_empty - tests whether a list is empty
	list_empty-测试列表是否为空
 * @head: the list to test.
	要测试的列表。
 */
static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

/*
 * Insert a new entry between two known consecutive entries.
 *	在两个已知的连续条目之间插入一个新条目。
 * This is only for internal list manipulation where we know
	这只适用于我们知道的内部列表操作
 * the prev/next entries already!
 */
static inline void __list_add(struct list_head *_new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = _new;
	_new->next = next;
	_new->prev = prev;
	prev->next = _new;
}

/**
 * list_add_tail - add a new entry
	list_add_tail-添加一个新条目
 * @new: new entry to be added
	要添加的新条目
 * @head: list head to add it before
	列出要在之前添加的标题
 *
 * Insert a new entry before the specified head.
	在指定标题之前插入一个新条目。
 * This is useful for implementing queues.
	这对于实现队列很有用。
 */
static inline void list_add_tail(struct list_head *_new, struct list_head *head)
{
	__list_add(_new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
	通过创建上一个/下一个条目来删除列表条目
 * point to each other.
 *	相互指向。
 * This is only for internal list manipulation where we know
	这只适用于我们知道的内部列表操作
 * the prev/next entries already!
	上一个/下一个条目已经存在！
 */
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)
/**
 * list_del - deletes entry from list.
	list_del-从列表中删除条目。
 * @entry: the element to delete from the list.
	要从列表中删除的元素。
 * Note: list_empty() on entry does not return true after this, the entry is
	条目上的list_empty（）在此之后不返回true，该条目为
 * in an undefined state.
	处于未定义状态。
 */
static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	entry->next = (struct list_head*)LIST_POISON1;
	entry->prev = (struct list_head*)LIST_POISON2;
}
#endif
