# C-_coding_space

# to create a new repository
echo "# C-_coding_space" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/anshpn8/C-_coding_space.git
git push -u origin main

# when we push the code while working
git add .
git commit -m "first modified commit"
git push -u origin main

# when need to download the code from the repository to new pc, we need to clone the repository
git clone https://github.com/anshpn8/Java_WorkSpace.git 

# when ever we open the repository at any day, first we pull the code
git pull origin main
git add .
git commit -m "first commit"
git push -u origin main