import psutil
from time import sleep
from math import floor
from collections import deque

# Get CPU Usage
# cpu_usage = psutil.cpu_percent(0.5, True)


metrics_history = {
    "cpu_util": "0",
    "cpu_freq": "0",
    "memory_percentage": "0",
    "memory_used": "0"
                   }

# def GetCPUUtil(interval, show_all_cpus):
#     util = psutil.cpu_percent(interval, show_all_cpus)
#     return util


def GetCPUUtil():
    while True: 
        cpuUtilSnapshot = psutil.cpu_percent(interval=None)  # non-blocking
        metrics_history["cpu_util"] = cpuUtilSnapshot
        sleep(1)

def GetCPUFreq():
    while True:
        cpuFreqSnapshot = psutil.cpu_freq(False)
        print(cpuFreqSnapshot.current)
        metrics_history["cpu_freq"] = floor(cpuFreqSnapshot.current)
        sleep(1)

def GetMemoryUsage():
    while True:
        memoryPercentSnapshot = psutil.virtual_memory()
        metrics_history["memory_percentage"] = memoryPercentSnapshot.percent
        metrics_history["memory_used"] = f"{memoryPercentSnapshot.used / 1000000:.1f}"
        sleep(1)

def GetLatestMetrics():
    """Return latest snapshot"""
    return metrics_history


