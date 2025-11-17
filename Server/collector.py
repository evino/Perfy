import psutil
from time import sleep
from collections import deque

# Get CPU Usage
# cpu_usage = psutil.cpu_percent(0.5, True)

# Keep a small history of metrics (optional)
history_length = 100
metrics_history = deque(maxlen=history_length)

# def GetCPUUtil(interval, show_all_cpus):
#     util = psutil.cpu_percent(interval, show_all_cpus)
#     return util


def GetCPUUtil():
    while True: 
        snapshot = {
            "cpu_percent": psutil.cpu_percent(interval=None),  # non-blocking
        }
        metrics_history.append(snapshot)
        sleep(1)

def GetLatestMetrics():
    """Return latest snapshot"""
    if metrics_history:
        return metrics_history[-1]
    return {}


