
#include "alarme.h"

#include "etatRelais.h"             //variable commun declarer dans un fichier sur etat de sorti des relais
/*

Faisons l'expérience :
Cliquez sur cette URL (ou copiez-collez-là dans la barre d'adresse d'un navigateur).
https://api.thingspeak.com/update?api_key=GBAJRPBIS940YBL6&field1=22
Puis allez voir la chaine qui reçoit l'info : https://thingspeak.com/channels/320552
Jouez en changeant la valeur qu'il y a après « field1= » tout à la fin de l'URL. Par exemple :
https://api.thingspeak.com/update?api_key=GBAJRPBIS940YBL6&field1=18
https://api.thingspeak.com/update?api_key=GBAJRPBIS940YBL6&field1=26



https://www.wiki.lesfabriquesduponant.net/images/8/81/Tuto7-Tutoriel-Thingspeak.pdf



(c) 2019 Microsoft Corporation. Tous droits réservés.

C:\Users\User>git pull
fatal: not a git repository (or any of the parent directories): .git

C:\Users\User>git status
fatal: not a git repository (or any of the parent directories): .git

C:\Users\User>cd C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>git status
On branch master
Your branch is ahead of 'origin/master' by 2 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    alarme.cpp
        deleted:    alarme.h

no changes added to commit (use "git add" and/or "git commit -a")

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>git pull
Already up to date.

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>git retore alarme.ccp
git: 'retore' is not a git command. See 'git --help'.

The most similar command is
        restore

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>git retore alarme.h
git: 'retore' is not a git command. See 'git --help'.

The most similar command is
        restore

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>git status
On branch master
Your branch is ahead of 'origin/master' by 2 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    alarme.cpp
        deleted:    alarme.h

no changes added to commit (use "git add" and/or "git commit -a")

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>git checkout alarme.cpp
Updated 1 path from the index

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>git checkout alarme.h
Updated 1 path from the index

C:\Users\User\Documents\github\test\aquarium-wifi\sketch_jul27a>




https://www.tutorielsenfolie.com/tutoriels-58-git-restauration-fichiers.html
*/