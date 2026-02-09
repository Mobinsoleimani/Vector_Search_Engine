from sentence_transformers import SentenceTransformer
import numpy as np
import struct
model = SentenceTransformer('all-MiniLM-L6-v2', device="cpu")

def embedid_engine(text:str):
    vec = model.encode(
        text,
        convert_to_numpy=True,
        normalize_embeddings=True
    )
    return vec.astype(np.float32)

embedding = embedid_engine(input("add your model: "))

file = 'vector.bin'

dim = embedding.shape[0]
num = 1

with open("vector.bin", "wb") as f:
    f.write(struct.pack("ii", num, dim))
    f.write(embedding.tobytes())
with open("vector.txt",mode = 'w') as vector:
    vector.write(str(embedding))
    vector.close()