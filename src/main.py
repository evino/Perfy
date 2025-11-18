from fastapi import FastAPI, WebSocket
from fastapi.responses import FileResponse
from pathlib import Path
from collector import GetCPUUtil, GetCPUFreq, GetMemoryUsage, GetLatestMetrics
import threading
import asyncio


app = FastAPI()

threading.Thread(target=GetCPUUtil, daemon=True).start()
threading.Thread(target=GetCPUFreq, daemon=True).start()
threading.Thread(target=GetMemoryUsage, daemon=True).start()


@app.get("/")
def raw_data():
    # __file__ is ServerSide/main.py
    frontend_file = Path(__file__).parent.parent / "src" / "FrontEnd" / "index.html"
    return FileResponse(frontend_file)

@app.get("/dashboard")
def dashboard_data():
    # __file__ is ServerSide/main.py
    frontend_file = Path(__file__).parent.parent / "src" / "FrontEnd" / "dashboard.html"
    return FileResponse(frontend_file)

@app.get("/ping")
def ping():
    return {"status": "ok"}

@app.get("/metrics")
def metrics():
    # Placeholder; will be replaced by collector later
    return GetLatestMetrics()

@app.websocket("/metricsWS")
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
    host_ip="0.0.0.0"
    uvicorn.run("main:app", host=host_ip, port=8000, reload=True)
    
