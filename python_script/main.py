from sentence_transformers import SentenceTransformer
import numpy as np
import struct
import os
model = SentenceTransformer('all-MiniLM-L6-v2', device="cpu")

def embedid_engine(text:str):
    vec = model.encode(
        text,
        convert_to_numpy=True,
        normalize_embeddings=True
    )
    return vec.astype(np.float32)

data=input("add your input text: ")

embedding = embedid_engine(data)

file = 'vector.bin'

dim = embedding.shape[0]
num = 1
file_exists = os.path.isfile(file)
with open(file, "ab") as f:
    if not file_exists:
        f.write(struct.pack("ii", 1, dim))
    f.write(embedding.tobytes())
with open("vector.txt",mode = 'a',encoding="utf-8") as vector:
    vector.write(data + "\n")
    vector.close()


user_input = input("add your input query: ")

embedding_query = embedid_engine(user_input)

with open("/home/hello-world/mini_vector_search_engine/cpp_engine/query_test.bin",mode = 'wb') as query:
    query.write(embedding_query.tobytes())
    query.close()