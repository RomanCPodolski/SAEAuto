# Developer guidelines

This section describes guidelines to follow during the development process.
If you are not a member of the development Team (aka. the Braintrust) you can skip this section.
The conventions in this sections proofed to be very useful for teams of 5 - 10 people.
All of those conventions are proposals, which means you don't have to follow them, if you feel that they hold you back.
Always use the right tool for the job (don't use sledgehammer to crack a nut).
But keep in mind that conventions only make sense if everyone obeys them.

## Git

If you never used git before, read some sections 1,2 and 3 of [Pro Git](https://git-scm.com/book/en/v2) and make yourself comfortable using it.
You don't need to be a pro, but you'll need to understand some basic concepts.
If you know how to:
* add / commit code
* pull code from the repository
* push code to the repository
* create / checkout a branch
* merge / rebase branches and resolve conflicts
* read the log

You'll be fine.

### Push / Pull
`git pull --rebase` is the new `git pull`!
Never, ever under any circumstances go `git push --force`!


### Branching
Please follow a watered down version of [Git-Flow](http://danielkummer.github.io/git-flow-cheatsheet/),
inspired by [this blog post](http://endoflineblog.com/gitflow-considered-harmful) during development.
Use `master` `develop` and `feature/*` branches for your workflow.

#### `master`
Contains code which is ready for submission / release.
Code in this branch should be:
* runnable (you have to be sure that nothing breaks after checking it out)
* fully documented
* fully tested (best by unit tests / second best manually)
* `cpplint` clean (0 - Warnings)
* very unlikely to be changed in the near future

#### `develop`
Contains code which is under development / not finished yet, but also not completely experimental.
It should be:

* mostly runnable (if it runs on your machine, that's enough)
* documented (Add 'TODO: doc' comments to places, where you miss documentation)
* tested

#### `feature/*`
Contains experimental code or code what is still heavy under development.
If you don't feel like `feature/*` branches fit in your development process, omit them.
But, since they enable you to multitask, I encourage you to use them.
An example:
Say you want to code an awsome controller for the steering, but you are not sure it this code / idea makes it in the final project.
Further you know, that you'll have to make code changes, that affect the existing code base and make it temporary not runnable.
You branch `feature/control` from the current `develop` branch, and start working on your idea there.
Whatever happens next, you are good to go.
If your Idea turns out to be great, rebase `feature/kmeans` and merge onto `develop`, after work on the feature is finished.
Then delete your `feature/kmeans` branch; you don't need it anymore.
If it turn out to be a dead end, delete the branch, and go back to where you started.
This principle enables you to have several `feature/*` branches in parallel, and multitask.
Please note that during this entire process it is not necessary to push this branch to github, since you are the only on working on it.
Anyway, if you collaborate on a feature, feel free to publish to github.
Code in feature branches:

* does not follow any rules - go nuts.

### Commiting Code
Always use `git add [--patch | -p]` to add code to your commit. Never under any circumstances do `git add [--all | -A]`, even if you are a 100% sure that you know whats added to the commit. Commits should be [atomic](https://seesparkbox.com/foundry/atomic_commits_with_git), which means:
* commit each fix or task as a separate change
* only commit when a block of work is complete
* commit each change separately

Inspired by [Tim Pope](http://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html), please format your commit messages like this:

```
<type of commit>(<module>): Capitalized, short (50 chars or less) summary

More detailed explanatory text, if necessary.  Wrap it to about 72
characters or so.  In some contexts, the first line is treated as the
subject of an email and the rest of the text as the body.  The blank
line separating the summary from the body is critical (unless you omit
the body entirely); tools like rebase can get confused if you run the
two together.

Write your commit message in the present tense: "Fix bug" and not "Fixed
bug."  This convention matches up with commit messages generated by
commands like git merge and git revert.

Further paragraphs come after blank lines.

- Bullet points are okay, too

- Typically a hyphen or asterisk is used for the bullet, preceded by a
  single space, with blank lines in between, but conventions vary here

- Use a hanging indent

```

type of commit could be:
* `wip` - work in progress - use this one for unfinished stuff
* `feat` - finished features - use this one for finished stuff
* `test` - test code / test results / test automation
* `art` - artifacts - like plots, reports, generated stuff
* `refactor` - use this one for changes style but not functionality.
* `chore` - work on tools (such as adding something to `.gitignore`)
* `doc` - documentation in the code or work on the report

if you need some examples, run `$ git log`.

Always `git pull --rebase` before you push!

## Make / WAF 
TODO
