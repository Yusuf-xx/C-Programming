# C-Programming

## Cloning this Repository

The following instructions are adapted from the Github documentation on [duplicating a repository](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/duplicating-a-repository). The procedure below walks you through creating github repository that you can use for development.

1. Go [here](https://github.com/new) to create a new repository under your account. Pick a name (e.g. `C-Programming`) and select **Private/Public** for the repository visibility level.
2. On your development machine, create a bare clone of the public C-Programming repository:
   ```
   $ git clone --bare https://github.com/Yusuf-xx/C-Programming.git C-Programming-public
   ```
3. Next, [mirror](https://git-scm.com/docs/git-push#Documentation/git-push.txt---mirror) the public C-Programming repository to your own private C-Programming repository. Suppose your GitHub name is `student` and your repository name is `C-Programming-private`. The procedure for mirroring the repository is then:
   ```
   $ cd C-Programming-public
   
   # If you pull / push over HTTPS
   $ git push https://github.com/student/C-Programming-private.git master

   # If you pull / push over SSH
   $ git push git@github.com:student/C-Programming-private.git master
   ```
   This copies everything in the public C-Programming repository to your own private repository. You can now delete your local clone of the public repository:
   ```
   $ cd ..
   $ rm -rf C-Programming-public
   ```
4. Clone your private repository to your development machine:
   ```
   # If you pull / push over HTTPS
   $ git clone https://github.com/student/C-Programming-private.git

   # If you pull / push over SSH
   $ git clone git@github.com:student/C-Programming-private.git
   ```
5. Add the public C-Programming repository as a second remote. This allows you to retrieve changes from the CMU-DB repository and merge them with your solution throughout the semester:
   ```
   $ git remote add public https://github.com/cmu-db/C-Programming.git
   ```
   You can verify that the remote was added with the following command:
   ```
   $ git remote -v
   origin	https://github.com/student/C-Programming-private.git (fetch)
   origin	https://github.com/student/C-Programming-private.git (push)
   public	https://github.com/cmu-db/C-Programming.git (fetch)
   public	https://github.com/cmu-db/C-Programming.git (push)
   ```
6. You can now pull in changes from the public BusTub repository as needed with:
   ```
   $ git pull public master
   ```
7. **Disable GitHub Actions** from the project settings of your private repository, otherwise you may run out of GitHub Actions quota.
   ```
   Settings > Actions > General > Actions permissions > Disable actions.
   ```

We suggest working on your projects in separate branches. If you do not understand how Git branches work, [learn how](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging). If you fail to do this, you might lose all your work at some point in the semester, and nobody will be able to help you.
