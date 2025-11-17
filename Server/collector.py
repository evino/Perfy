import psutil
import time

# Get CPU Usage
# cpu_usage = psutil.cpu_percent(0.5, True)

def GetCPUUtil(interval, show_all_cpus):
    util = psutil.cpu_percent(interval, show_all_cpus)
    return util

while (True):
    print(GetCPUUtil(0.1, False))
    time.sleep(1)
    # break
