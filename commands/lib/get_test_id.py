from dataclasses import dataclass

@dataclass
class TestId:
    is_valid: bool
    id: str

def remove_suffix(input_str, suffix):
  if input_str.endswith(suffix):
      return input_str[:-len(suffix)]
  return input_str

def get_test_id(path):
  id = path.replace("\\", "/")
  id = id.replace("/Debug/", "/")
  id = id.replace("/src/", "/")

  parts = id.split("/Tests/")
  if len(parts) > 1:
      id = id.split("/Tests/")[1]
  
  if id.startswith("src/"):
      id = id[len("src/"):]

  id = remove_suffix(id, '.c')
  id = remove_suffix(id, '.exe')
  id = remove_suffix(id, '.test')

  return id
