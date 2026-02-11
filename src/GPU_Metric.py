
import pynvml
import time

def get_gpu_metrics():
	pynvml.nvmlInit()
	device_count = pynvml.nvmlDeviceGetCount()
	metrics = []

	for i in range(device_count):
		handle = pynvml.nvmlDeviceGetHandleByIndex(i)
		name = pynvml.nvmlDeviceGetName(handle)
		if isinstance(name, bytes):
			name = name.decode('utf-8')

		utilization = pynvml.nvmlDeviceGetUtilizationRates(handle)
		memory = pynvml.nvmlDeviceGetMemoryInfo(handle)

		metrics.append({
			'device': i,
			'name': name,
			'temperature': pynvml.nvmlDeviceGetTemperature(handle, pynvml.NVML_TEMPERATURE_GPU),
			'utilization': {
				'gpu': utilization.gpu,
				'memory': utilization.memory
			},
			'memory': {
				'used': memory.used,
				'total': memory.total,
				'free': memory.free
			}
		})

	pynvml.nvmlShutdown()
	return metrics

if __name__ == "__main__":
	try:
		while True:
			print("GPU Metrics:")
			for metric in get_gpu_metrics():
				print(f"Device {metric['device']} ({metric['name']})")
				print(f"  Temperature: {metric['temperature']}°C")
				print(f"  Utilization: {metric['utilization']['gpu']}% GPU, {metric['utilization']['memory']}% Memory")
				print(f"  Memory: {metric['memory']['used']}/{metric['memory']['total']} (Free: {metric['memory']['free']})")
				print()
			time.sleep(5)
	except KeyboardInterrupt:
		print("Metrics collection stopped.")
