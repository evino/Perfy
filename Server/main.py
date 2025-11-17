from fastapi import FastAPI

app = FastAPI()

@app.get("/ping")
def ping():
    return {"status": "ok"}

@app.get("/metrics")
def metrics():
    # Placeholder; will be replaced by collector later
    return {
        "cpu": "0%",
        "memory": "0MB",
        "ipc": 0
    }


if __name__ == "__main__":
    import uvicorn
    uvicorn.run("main:app", host="0.0.0.0", port=8000, reload=True)
    