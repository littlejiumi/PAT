import re

if __name__ == "__main__":
  bad_keys = input()
  raw_keys = input()
  for key in bad_keys:
    if key == '+':
        raw_keys = re.sub(r"[A-Z]+","",raw_keys)
    else:
      raw_keys = raw_keys.replace(key.lower(),'')
      raw_keys = raw_keys.replace(key.upper(),'')
  print(raw_keys)
