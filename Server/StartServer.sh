#!/bin/bash
# Source this file, not run as executable!!

# Activate Python virtual environment
source ../venv/bin/activate

# Start FastAPI with Uvicorn
uvicorn main:app --reload --host 0.0.0.0 --port 8000
