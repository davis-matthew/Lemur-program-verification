from threading import Thread
from ollama import Client, Options
from os import environ

PORTS = [int(x) for x in environ['LLM_PORTS'].split(",")]
MODEL_NAME = "qwen2.5-coder:32b-instruct-q4_K_M"
TEMPERATURE = 0.8
N_CTX = 2047

def loadLLM():
    def _load(p):
        while True:
            try:
                Client(host="http://127.0.0.1:" + str(p)).chat(
                    model=MODEL_NAME,
                    options=Options(temperature=TEMPERATURE, num_ctx=N_CTX),
                    messages=[{"role": "user", "content": "1 + 1?" }],
                    keep_alive="-1m",
                )
                return
            except:
                pass
    ts = []
    for p in PORTS:
        t = Thread(target=_load, args=(p,))
        t.start()
        ts.append(t)
    for t in ts:
        t.join()

loadLLM()
