from fastapi import FastAPI
from collector import GetCPUUtil, GetLatestMetrics
import threading

app = FastAPI()

threading.Thread(target=GetCPUUtil, daemon=True).start()

@app.get("/ping")
def ping():
    return {"status": "ok"}

@app.get("/metrics")
def metrics():
    # Placeholder; will be replaced by collector later
    return GetLatestMetrics()


if __name__ == "__main__":
    import uvicorn
    uvicorn.run("main:app", host="0.0.0.0", port=8000, reload=True)
    