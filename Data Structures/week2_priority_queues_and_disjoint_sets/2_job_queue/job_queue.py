# python3

from collections import namedtuple
import heapq 


AssignedJob = namedtuple("AssignedJob", ["worker", "started_at"])


def assign_jobs(n_workers, jobs):
    result = []
    next_free_time = [[0,i] for i in range(n_workers)]
    heapq.heapify(next_free_time) 
    for i in jobs:
        thread = heapq.heappop(next_free_time)
        start_time = thread[0]
        thread_id = thread[1]
        result.append(AssignedJob(thread_id, start_time))
        heapq.heappush(next_free_time, [start_time+i,thread_id])
    return result


def main():
    n_workers, n_jobs = map(int, input().split())
    jobs = list(map(int, input().split()))
    assert len(jobs) == n_jobs

    assigned_jobs = assign_jobs(n_workers, jobs)

    for job in assigned_jobs:
        print(job.worker, job.started_at)


if __name__ == "__main__":
    main()
