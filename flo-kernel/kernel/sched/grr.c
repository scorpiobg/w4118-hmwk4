/*
 * Round-Robin Scheduling Class (mapped to the SCHED_GRR policy)
 */

#include "sched.h"

#include <linux/slab.h>

#define BASE_WRR_TIME_SLICE (100 * HZ / 1000) /* time slice of 100ms */

static int do_sched_rt_period_timer(struct rt_bandwidth *rt_b, int overrun);

struct rt_bandwidth def_rt_bandwidth;

static enum hrtimer_restart sched_rt_period_timer(struct hrtimer *timer)
{
}

void init_rt_bandwidth(struct rt_bandwidth *rt_b, u64 period, u64 runtime)
{
}

static void start_rt_bandwidth(struct rt_bandwidth *rt_b)
{
}

void init_rt_rq(struct rt_rq *rt_rq, struct rq *rq)
{
}

static void destroy_rt_bandwidth(struct rt_bandwidth *rt_b)
{
}

#define rt_entity_is_task(rt_se) (!(rt_se)->my_q)

static inline struct task_struct *rt_task_of(struct sched_rt_entity *rt_se)
{
}

static inline struct rq *rq_of_rt_rq(struct rt_rq *rt_rq)
{
}

static inline struct rt_rq *rt_rq_of_se(struct sched_rt_entity *rt_se)
{
}

void free_rt_sched_group(struct task_group *tg)
{
}

void init_tg_rt_entry(struct task_group *tg, struct rt_rq *rt_rq,
		struct sched_rt_entity *rt_se, int cpu,
		struct sched_rt_entity *parent)
{
}

int alloc_rt_sched_group(struct task_group *tg, struct task_group *parent)
{
}

static inline struct task_struct *rt_task_of(struct sched_rt_entity *rt_se)
{
}

static inline struct rq *rq_of_rt_rq(struct rt_rq *rt_rq)
{
}

static inline struct rt_rq *rt_rq_of_se(struct sched_rt_entity *rt_se)
{
}

void free_rt_sched_group(struct task_group *tg) { }

int alloc_rt_sched_group(struct task_group *tg, struct task_group *parent)
{
}

static inline int rt_overloaded(struct rq *rq)
{
}

static inline void rt_set_overload(struct rq *rq)
{
}

static inline void rt_clear_overload(struct rq *rq)
{
}

static void update_rt_migration(struct rt_rq *rt_rq)
{
}

static void inc_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

static void dec_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

static inline int has_pushable_tasks(struct rq *rq)
{
}

static void enqueue_pushable_task(struct rq *rq, struct task_struct *p)
{
}

static void dequeue_pushable_task(struct rq *rq, struct task_struct *p)
{
}

#else

static inline void enqueue_pushable_task(struct rq *rq, struct task_struct *p)
{
}

static inline void dequeue_pushable_task(struct rq *rq, struct task_struct *p)
{
}

static inline
void inc_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

static inline
void dec_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

#endif /* CONFIG_SMP */

static inline int on_rt_rq(struct sched_rt_entity *rt_se)
{
}

#ifdef CONFIG_RT_GROUP_SCHED

static inline u64 sched_rt_runtime(struct rt_rq *rt_rq)
{
}

static inline u64 sched_rt_period(struct rt_rq *rt_rq)
{
}

typedef struct task_group *rt_rq_iter_t;

static inline struct task_group *next_task_group(struct task_group *tg)
{
}

#define for_each_rt_rq(rt_rq, iter, rq)					\
	for (iter = container_of(&task_groups, typeof(*iter), list);	\
		(iter = next_task_group(iter)) &&			\
		(rt_rq = iter->rt_rq[cpu_of(rq)]);)

static inline void list_add_leaf_rt_rq(struct rt_rq *rt_rq)
{
}

static inline void list_del_leaf_rt_rq(struct rt_rq *rt_rq)
{
}

#define for_each_leaf_rt_rq(rt_rq, rq) \
	list_for_each_entry_rcu(rt_rq, &rq->leaf_rt_rq_list, leaf_rt_rq_list)

#define for_each_sched_rt_entity(rt_se) \
	for (; rt_se; rt_se = rt_se->parent)

static inline struct rt_rq *group_rt_rq(struct sched_rt_entity *rt_se)
{
}

static void enqueue_rt_entity(struct sched_rt_entity *rt_se, bool head);
static void dequeue_rt_entity(struct sched_rt_entity *rt_se);

static void sched_rt_rq_enqueue(struct rt_rq *rt_rq)
{
}

static void sched_rt_rq_dequeue(struct rt_rq *rt_rq)
{
}

static inline int rt_rq_throttled(struct rt_rq *rt_rq)
{
}

static int rt_se_boosted(struct sched_rt_entity *rt_se)
{
}

#ifdef CONFIG_SMP
static inline const struct cpumask *sched_rt_period_mask(void)
{
}
#else
static inline const struct cpumask *sched_rt_period_mask(void)
{
}
#endif

static inline
struct rt_rq *sched_rt_period_rt_rq(struct rt_bandwidth *rt_b, int cpu)
{
}

static inline struct rt_bandwidth *sched_rt_bandwidth(struct rt_rq *rt_rq)
{
}

#else /* !CONFIG_RT_GROUP_SCHED */

static inline u64 sched_rt_runtime(struct rt_rq *rt_rq)
{
}

static inline u64 sched_rt_period(struct rt_rq *rt_rq)
{
}

typedef struct rt_rq *rt_rq_iter_t;

#define for_each_rt_rq(rt_rq, iter, rq) \
	for ((void) iter, rt_rq = &rq->rt; rt_rq; rt_rq = NULL)

static inline void list_add_leaf_rt_rq(struct rt_rq *rt_rq)
{
}

static inline void list_del_leaf_rt_rq(struct rt_rq *rt_rq)
{
}

#define for_each_leaf_rt_rq(rt_rq, rq) \
	for (rt_rq = &rq->rt; rt_rq; rt_rq = NULL)

#define for_each_sched_rt_entity(rt_se) \
	for (; rt_se; rt_se = NULL)

static inline struct rt_rq *group_rt_rq(struct sched_rt_entity *rt_se)
{
}

static inline void sched_rt_rq_enqueue(struct rt_rq *rt_rq)
{
}

static inline void sched_rt_rq_dequeue(struct rt_rq *rt_rq)
{
}

static inline int rt_rq_throttled(struct rt_rq *rt_rq)
{
}

static inline const struct cpumask *sched_rt_period_mask(void)
{
}

static inline
struct rt_rq *sched_rt_period_rt_rq(struct rt_bandwidth *rt_b, int cpu)
{
}

static inline struct rt_bandwidth *sched_rt_bandwidth(struct rt_rq *rt_rq)
{
}

#endif /* CONFIG_RT_GROUP_SCHED */

#ifdef CONFIG_SMP
/*
 * We ran out of runtime, see if we can borrow some from our neighbours.
 */
static int do_balance_runtime(struct rt_rq *rt_rq)
{
}

/*
 * Ensure this RQ takes back all the runtime it lend to its neighbours.
 */
static void __disable_runtime(struct rq *rq)
{
}

static void disable_runtime(struct rq *rq)
{
}

static void __enable_runtime(struct rq *rq)
{
}

static void enable_runtime(struct rq *rq)
{
}

int update_runtime(struct notifier_block *nfb, unsigned long action, void *hcpu)
{
}

static int balance_runtime(struct rt_rq *rt_rq)
{
}

#else /* !CONFIG_SMP */
static inline int balance_runtime(struct rt_rq *rt_rq)
{
}
#endif /* CONFIG_SMP */

static int do_sched_rt_period_timer(struct rt_bandwidth *rt_b, int overrun)
{
}

static inline int rt_se_prio(struct sched_rt_entity *rt_se)
{
#ifdef CONFIG_RT_GROUP_SCHED
#endif
}

static int sched_rt_runtime_exceeded(struct rt_rq *rt_rq)
{
}

/*
 * Update the current task's runtime statistics. Skip current tasks that
 * are not in our scheduling class.
 */
static void update_curr_rt(struct rq *rq)
{
}

#if defined CONFIG_SMP

static void
inc_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio)
{
}

static void
dec_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio)
{
}

#else /* CONFIG_SMP */

static inline
void inc_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio) {}
static inline
void dec_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio) {}

#endif /* CONFIG_SMP */

#if defined CONFIG_SMP || defined CONFIG_RT_GROUP_SCHED
static void
inc_rt_prio(struct rt_rq *rt_rq, int prio)
{
}

static void
dec_rt_prio(struct rt_rq *rt_rq, int prio)
{
}

#else

static inline void inc_rt_prio(struct rt_rq *rt_rq, int prio) {}
static inline void dec_rt_prio(struct rt_rq *rt_rq, int prio) {}

#endif /* CONFIG_SMP || CONFIG_RT_GROUP_SCHED */

#ifdef CONFIG_RT_GROUP_SCHED

static void
inc_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

static void
dec_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

#else /* CONFIG_RT_GROUP_SCHED */

static void
inc_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

static inline
void dec_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq) {}

#endif /* CONFIG_RT_GROUP_SCHED */

static inline
void inc_rt_tasks(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

static inline
void dec_rt_tasks(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}

static void __enqueue_rt_entity(struct sched_rt_entity *rt_se, bool head)
{
}

static void __dequeue_rt_entity(struct sched_rt_entity *rt_se)
{
}

/*
 * Because the prio of an upper entry depends on the lower
 * entries, we must remove entries top - down.
 */
static void dequeue_rt_stack(struct sched_rt_entity *rt_se)
{
}

static void enqueue_rt_entity(struct sched_rt_entity *rt_se, bool head)
{
}

static void dequeue_rt_entity(struct sched_rt_entity *rt_se)
{
}

/*
 * Adding/removing a task to/from a priority array:
 */
static void
enqueue_task_rt(struct rq *rq, struct task_struct *p, int flags)
{
}

static void dequeue_task_rt(struct rq *rq, struct task_struct *p, int flags)
{
}

/*
 * Put task to the head or the end of the run list without the overhead of
 * dequeue followed by enqueue.
 */
static void
requeue_rt_entity(struct rt_rq *rt_rq, struct sched_rt_entity *rt_se, int head)
{
}

static void requeue_task_rt(struct rq *rq, struct task_struct *p, int head)
{
}

static void yield_task_rt(struct rq *rq)
{
}

#ifdef CONFIG_SMP
static int find_lowest_rq(struct task_struct *task);

static int
select_task_rq_rt(struct task_struct *p, int sd_flag, int flags)
{
}

static void check_preempt_equal_prio(struct rq *rq, struct task_struct *p)
{
}

#endif /* CONFIG_SMP */

/*
 * Preempt the current task with a newly woken task if needed:
 */
static void check_preempt_curr_rt(struct rq *rq, struct task_struct *p, int flags)
{
#ifdef CONFIG_SMP
#endif
}

static struct sched_rt_entity *pick_next_rt_entity(struct rq *rq,
						   struct rt_rq *rt_rq)
{
}

static struct task_struct *_pick_next_task_rt(struct rq *rq)
{
}

static struct task_struct *pick_next_task_rt(struct rq *rq)
{
#ifdef CONFIG_SMP
#endif
}

static void put_prev_task_rt(struct rq *rq, struct task_struct *p)
{
}

#ifdef CONFIG_SMP

/* Only try algorithms three times */
#define RT_MAX_TRIES 3

static int pick_rt_task(struct rq *rq, struct task_struct *p, int cpu)
{
}

/* Return the second highest RT task, NULL otherwise */
static struct task_struct *pick_next_highest_task_rt(struct rq *rq, int cpu)
{
}

static DEFINE_PER_CPU(cpumask_var_t, local_cpu_mask);

static int find_lowest_rq(struct task_struct *task)
{
}

/* Will lock the rq it finds */
static struct rq *find_lock_lowest_rq(struct task_struct *task, struct rq *rq)
{
}

static struct task_struct *pick_next_pushable_task(struct rq *rq)
{
}

/*
 * If the current CPU has more than one RT task, see if the non
 * running task can migrate over to a CPU that is running a task
 * of lesser priority.
 */
static int push_rt_task(struct rq *rq)
{
}

static void push_rt_tasks(struct rq *rq)
{
}

static int pull_rt_task(struct rq *this_rq)
{
}

static void pre_schedule_rt(struct rq *rq, struct task_struct *prev)
{
}

static void post_schedule_rt(struct rq *rq)
{
}

/*
 * If we are not running and we are not going to reschedule soon, we should
 * try to push tasks away now
 */
static void task_woken_rt(struct rq *rq, struct task_struct *p)
{
}

static void set_cpus_allowed_rt(struct task_struct *p,
				const struct cpumask *new_mask)
{
}

/* Assumes rq->lock is held */
static void rq_online_rt(struct rq *rq)
{
}

/* Assumes rq->lock is held */
static void rq_offline_rt(struct rq *rq)
{
}

/*
 * When switch from the rt queue, we bring ourselves to a position
 * that we might want to pull RT tasks from other runqueues.
 */
static void switched_from_rt(struct rq *rq, struct task_struct *p)
{
	/*
	 * If there are other RT tasks then we will reschedule
	 * and the scheduling of the other RT tasks will handle
	 * the balancing. But if we are the last RT task
	 * we may need to handle the pulling of RT tasks
	 * now.
	 */
}

void init_sched_rt_class(void)
{
}
#endif /* CONFIG_SMP */

/*
 * When switching a task to RT, we may overload the runqueue
 * with RT tasks. In this case we try to push them off to
 * other runqueues.
 */
static void switched_to_rt(struct rq *rq, struct task_struct *p)
{
#ifdef CONFIG_SMP
#endif /* CONFIG_SMP */
}

/*
 * Priority of the task has changed. This may cause
 * us to initiate a push or pull.
 */
static void
prio_changed_rt(struct rq *rq, struct task_struct *p, int oldprio)
{
}

static void watchdog(struct rq *rq, struct task_struct *p)
{
}

static void task_tick_rt(struct rq *rq, struct task_struct *p, int queued)
{
}

static void set_curr_task_rt(struct rq *rq)
{
}

static unsigned int get_rr_interval_rt(struct rq *rq, struct task_struct *task)
{
}


/*
 * All the scheduling class methods:
 */
const struct sched_class sched_grr_class = {
	.next			= &fair_sched_class,
	.enqueue_task		= enqueue_task_grr,
	.dequeue_task		= dequeue_task_grr,
	.yield_task		= yield_task_grr,
	.yield_to_task		= yield_to_task_grr,

	.check_preempt_curr	= check_preempt_wakeup,

	.pick_next_task		= pick_next_task_grr,
	.put_prev_task		= put_prev_task_grr,

#ifdef CONFIG_SMP
	.select_task_rq		= select_task_rq_grr,

	.rq_online		= rq_online_grr,
	.rq_offline		= rq_offline_grr,

	.task_waking		= task_waking_grr,
#endif

	.set_curr_task          = set_curr_task_grr,
	.task_tick		= task_tick_grr,
	.task_fork		= task_fork_grr,

	.prio_changed		= prio_changed_grr,
	.switched_from		= switched_from_grr,
	.switched_to		= switched_to_grr,

	.get_rr_interval	= get_rr_interval_grr,

#ifdef CONFIG_GRR_GROUP_SCHED
	.task_move_group	= task_move_group_grr,
#endif
};

#ifdef CONFIG_SCHED_DEBUG
extern void print_rt_rq(struct seq_file *m, int cpu, struct rt_rq *rt_rq);

void print_rt_stats(struct seq_file *m, int cpu)
{
}
#endif /* CONFIG_SCHED_DEBUG */