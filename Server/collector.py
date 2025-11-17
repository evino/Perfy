import psutil
from time import sleep
from collections import deque

# Get CPU Usage
# cpu_usage = psutil.cpu_percent(0.5, True)


metrics_history = {"CPU Util": "0%"}

# def GetCPUUtil(interval, show_all_cpus):
#     util = psutil.cpu_percent(interval, show_all_cpus)
#     return util


def GetCPUUtil():
    while True: 
        cpuUtilSnapshot = psutil.cpu_percent(interval=None),  # non-blocking
        metrics_history["CPU Util"] = cpuUtilSnapshot
        sleep(1)

def GetLatestMetrics():
    """Return latest snapshot"""
    return metrics_history


