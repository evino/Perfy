from fastapi import FastAPI, WebSocket
from collector import GetCPUUtil, GetLatestMetrics
import threading
import asyncio

app = FastAPI()

threading.Thread(target=GetCPUUtil, daemon=True).start()

@app.get("/ping")
def ping():
    return {"status": "ok"}

@app.get("/metrics")
def metrics():
    # Placeholder; will be replaced by collector later
    return GetLatestMetrics()

@app.websocket("/metricWS")
async def MetricsWebsocket(websocket: WebSocket):
    await websocket.accept()
    try:
        while True:
            data = GetLatestMetrics()
            await websocket.send_json(data)
            await asyncio.sleep(1) #update interval
    except Exception as e:
        print(f"WebSocket disconnected: {e}")


if __name__ == "__main__":
    import uvicorn
    uvicorn.run("main:app", host="0.0.0.0", port=8000, reload=True)
    