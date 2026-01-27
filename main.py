from sentence_transformers import SentenceTransformer

model = SentenceTransformer('all-MiniLM-L6-v2', device="cpu")

def embedid_engine(text:str):
    embedding = model.encode(text)
    return embedding

x = embedid_engine('i m happy')

with open("vector.txt",mode = 'w') as vector:
    vector.write(str(x))
    vector.close()