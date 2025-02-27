import os
def makeNewUserDir(username):
   if invalidUsername(username):
      print("Les noms d'utilisateur ne doivent pas contenir de caractères invalides")
      return False
   path = os.path.join('/home', username)
   try:
      raisePrivileges()
      os.mkdir(path, 0o700)
   except OSError as e:
      print("Impossible de créer le répertoire utilisateur pour :", username, e)
      return False
   finally:
      lowerPrivileges()
      return True