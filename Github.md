# GitHub Guidelines - Plant Palace

## TLDR

- **Always branch from `development`, never from any other branch.**
- **Branch names** follow:
  `type/short-description` (all lowercase, hyphens for spaces)
  *Examples:*
  * `feat/greenhouse-controller`
  * `fix/state-transition-bug`
- **Allowed branch types:**
  - `feat/` = features
  - `fix/` = bug fixes
  - `doc/` = documentation
  - `chore/` = refactoring/setup
  - `test/` = tests
- **Commit messages follow this format:**
  `type(scope): short-description`
  Example: `feat(observer): implement stock update notifications`
- **One logical change per commit** - avoid mixing unrelated changes.
- **Pull Requests target the `development` branch only** and must use clear titles like:
   `feat(state): implement plant lifecycle transitions`
- **Use `Closes #<issue-number>` in the PR description** to automatically close the linked issue on merge.
- **Always use "Squash and Merge"** to keep a clean, readable history.
- **Every change must go through a PR with assigned reviewers** - no direct pushes to `development` or `main`.
- **After merge, branch is deleted automatically**, and you must pull the latest `development` before starting new work.

## Branch Naming Conventions

All work happens in **short-lived feature branches** off of the `development` branch.
Branch names must be **descriptive** and follow a consistent naming structure.

**Format:**

```
<type>/<short-description>
```

**Accepted types:**

| Prefix   | Purpose                               | Example                         |
| -------- | ------------------------------------- | ------------------------------- |
| `feat/`  | New features or functionality         | `feat/greenhouse-controller`    |
| `fix/`   | Bug fixes or patches                  | `fix/temperature-threshold-bug` |
| `doc/`   | Documentation updates                 | `doc/update-state-diagram`      |
| `chore/` | Maintenance or non-functional changes | `chore/update-cmake-config`     |
| `test/`  | Test-related changes                  | `test/add-unit-tests`           |

**Branching rules:**

* Always branch from `development`, not from `main`.
* Use **lowercase** letters, with hyphens to separate words.
* Keep names short but meaningful.
* Delete the branch after it's merged to keep the repository tidy. (should happen automatically on GitHub)

## Commit Message Conventions

Commit messages communicate *what* changed and *why*.
Each commit should represent a logical, self-contained change.

**Format:**

```
<type>(<scope>): <short-description>
<blank line>
<detailed-description>
```

Where:

* `<type>` is one of: `feat`, `fix`, `doc`, `chore`, `test`
* `<scope>` is the affected part of the codebase (e.g., `observer`, `state`, `inventory`)
* `<short-description>` is a concise summary (50 characters max)
* `<detailed-description>` (optional) gives context, reasoning, or side effects

**Example:**

```
feat(observer): implement push notification model

Added a new push-based observer pattern to the GreenhouseController.
Observers now receive updated temperature and humidity values directly.
```

**Guidelines:**

* Write commits in **present tense** ("add feature", not "added feature").
* Keep each commit focused on one logical change.
* Use multiple commits for separate changes instead of combining them.
* Avoid vague messages such as “update” or “fix stuff”.

## Pull Request Guidelines

All pull requests (PRs) must target the `development` branch.

**General rules:**

* Create a PR for every change - **do not push directly** to `development` or `main`.
* Assign at least **one reviewer** from the team.
* Ensure your branch builds and runs correctly before opening the PR.
* Provide a **clear, descriptive title** and **meaningful summary** of your changes.
* Reference related issues with keywords such as `Closes #12` or `Fixes #7`.
* Use the **default PR template** to include key details such as the scope, purpose, and testing steps.

**Example Pull Request title:**

```
feat(state): implement PlantState transitions and tests
```

**Example description:**

```
Added PlantState classes for seedling, mature, and wilting stages.
Includes a transition mechanism controlled by the greenhouse timer.

- [x] Added base PlantState class
- [x] Added SeedlingState, MatureState, and WiltingState
- [x] Added unit tests for transitions

Closes #18
```

### Merging Policy

* Only merge a PR **after review and approval**.
* Always use **"Squash and Merge"** to keep commit history clean.

**Why Squash and Merge?**

* Combines all commits from a feature branch into a single, meaningful commit on `development`.
* Prevents merge clutter from many small "WIP" commits.
* Ensures each commit on `development` represents a *complete, reviewed* change.
* Makes the commit history linear and easy to follow.

**Example:**

```
Before squash:
  * fix: typo
  * add temperature controller
  * update UML
  * cleanup

After squash:
  * feat(greenhouse): implement temperature controller
```

After merging, make sure that your branch is deleted (this should happen automatically). 

## Issue Tracking

**Important:** For any issues, bugs, new features, etc. create a new (sub)-issue on GitHub. Do not just communicate about issues on Whatsapp, Discord, or other platforms. This allows us to assign people to fix problems, etc.

GitHub Issues are used to record bugs, improvements, and new features.
Each issue should focus on **one clearly defined problem or goal**.

**When creating an issue:**

1. Use a clear, descriptive **title**.
2. Provide a **detailed description** of the problem, feature, or documentation task.
3. Use **labels** to categorize the issue.
4. Assign yourself or another team member.
5. Link related issues or pull requests for context.
6. Use checklists for multi-step tasks.

**Examples:**

* `feat: implement Iterator pattern for plant collection`
* `bug: PlantState does not transition after watering`

**Labels (Current):**

- bug - Something isn't working.
- blocked - Cannot proceed until a dependency is done.
- core - Critical domain logic; blocks other features if incomplete. (12 open issues)
- documentation - Improvements or additions to documentation. (11 open issues)
- duplicate - This issue or pull request already exists.
- enhancement - New feature or request.
- help wanted - Extra attention is needed.
- infrastructure - Tooling, adapters, file I/O, build, deployment. (3 open issues)
- invalid - This doesn't seem right.
- needs-review - Ready for code review and testing.
- owner:adriano - Primary owner: Adriano. (5 open issues)
- owner:bulelani - Primary owner: Bulelani. (3 open issues)
- owner:connor - Primary owner: Connor. (6 open issues)
- owner:johan - Primary owner: Johan. (9 open issues)
- owner:zoe - Primary owner: Zoe. (8 open issues)
- pattern - Implements a design pattern or its core classes. (13 open issues)
- priority:high - Must be shipped or implemented ASAP. (4 open issues)
- priority:low - Nice-to-have; schedule after higher priorities. (1 open issue)
- priority:normal - Standard priority for planned work. (26 open issues)
- question - Further information is requested.
- ux-integration - UI/UX wiring or end-to-end glue across subsystems. (2 open issues)
- wontfix - This will not be worked on.

Notes:
- Use at least one priority label and one owner label on new issues where possible.
- For design-pattern work, use `pattern` and follow the Design Pattern issue format (see below).

**Example Issue:**

```
Title: feat: add Command pattern for greenhouse automation

Description:
Implement the Command pattern to support queued greenhouse actions.

Tasks:
- [ ] Create base Command interface
- [ ] Implement WaterCommand and LightCommand
- [ ] Add test coverage for command execution
- [ ] Update UML diagram in /docs

Labels: enhancement, state
Assignee: @username
```

**Linking Issues and PRs:**

* Use `Closes #issue-number` in a PR description to automatically close an issue once merged.
* Example:

  ```
  Closes #24
  ```

### Design Pattern Issues

For issues that implement a design pattern, use the `pattern` label and structure the issue as follows (this mirrors the issue template available under New Issue → Design Pattern):

```
## Overview
High-level purpose and responsibilities.

## Participation & Relations
- Collaborates with: <subsystems>
- Consumed by: <client/UX owner>
- Exposes: `<publicAPIs>`

## Implementation Checklist
- [ ] Wire collaborating subsystems
- [ ] Implement core behavior
- [ ] Tests: happy path and edge cases

## Definition of Done
- [ ] UI can call 2-3 endpoints to complete a flow
- [ ] PR linked with “Closes #<issue>”
```

## Milestones

- M1: Foundation - Due by October 26, 2025
- M2: Final Behavior - Due by October 28, 2025
- M3: Orchestration and Finalisation - Due by October 31, 2025

When creating or grooming issues, assign them to the appropriate milestone to keep progress tracking accurate.

## General Best Practices

* Keep PRs **small and focused**. One logical change per PR.
* Run and pass **all tests** before submitting a PR.
* Write **clear, descriptive** commit messages and PR titles.
* Always keep your local branch up to date with `development` before pushing.
* Use **Issues** to plan or discuss features before implementing them.
* Do **not** merge into `main` directly; it should only reflect finalized and stable releases.

## Important Notes

* Please be professional and respectful in code reviews and comments.
* Use GitHub’s built-in features (like Projects, Milestones, and Labels) to keep the workflow organised and to keep track of progress.
* If you are unsure about any part of this workflow, please ask Johan for clarification.

## Thorough Example

### Scenario:

Johan is responsible for implementing the **Composite Pattern** for the greenhouse structure.

### 1. Issue Is Assigned

* Issue title: `feat/composite-greenhouse`
* Labels applied: `pattern`, `core`, `priority:high`, `owner:johan`, `milestone:sprint-1`
* Issue contains:

  * Overview, participation, checklist
  * Acceptance criteria
  * Dependencies (if any)

### 2. Branch Creation (from the Issue page)

* Johan navigates to the issue on GitHub.
* Under the **Development** panel (right sidebar), he clicks **Create a branch**.
* **Important:** He manually names the branch following team conventions:
  **`feat/composite-greenhouse`**
* **Base branch is set to `development`**, not `main` or any other branch.
* This automatically links the branch to the issue.

### 3. Local Development + Proper Commits

Johan writes code implementing the Composite pattern. Each logical step is a **separate commit**, following the conventional format:

Example commit messages:

```text
feat(composite): add GreenhouseComponent abstract base class
feat(composite): implement GreenhouseBed composite with add/remove/list child operations
fix(composite): correct traversal logic in getChild()
test(composite): add unit tests for composite structure and nested iteration
docs(composite): update greenhouse pattern documentation
```

### 4. Push the Branch

Johan pushes the branch to GitHub:

* This triggers GitHub to automatically show the branch as linked to the issue.

### 5. Open a Pull Request (PR)

* Target branch: `development`
* PR title (must follow convention):
  **`feat(composite): implement composite pattern for greenhouse structure`**
* PR description includes:

  * Summary of what the implementation achieves
  * Checklist of completed work
  * The critical line that auto-closes the issue:

    ```
    Closes #12
    ```

(where `#12` is the issue number)

### 6. Request Code Review

* Johan assigns **Connor** and **Zoe** as reviewers.
* Labels updated: `needs-review`

### 7. Code Review Process

* Connor reviews functionality and logic.
* Zoe reviews documentation, naming, pattern compliance.
* They leave comments, suggestions, or approve.
* If a bug is found during review, the reviewer leaves a comment on the issue requesting changes. 

Note: If a bug is found after review approval (and the PR is merged), a new issue must be created to track the bug fix (see "11. Handling Bugs" below).

If changes are requested:

* Johan makes updates and commits them to the *same branch*.
* The PR automatically updates with new commits.
* Reviewers re-approve once satisfied.
* This continues until all reviewers approve.

### 8. Approval & Merge

Once approved:

* Johan selects **"Squash and Merge"**
  * This keeps the commit history clean and merges all commits into one meaningful commit.
* Merge is made into `development`.
* The branch is deleted automatically (per team settings).
* Because the PR description included `Closes #12`, the **issue automatically moves to Done**.


### 9. Syncing the Local Repo

After merging, Johan pulls the latest `development` into his local repo to stay up to date.

### 10. Team Continues Development

Each team member repeats this workflow for their respective pattern or feature.

### 11. Handling Bugs

If a bug is found later related to the Composite pattern:

* A **new issue is created**, not reopened.
* Naming convention: `bug/composite-null-pointer`
* It is linked as a **sub-issue** of the original `feat/composite-greenhouse` using GitHub’s “Linked Issues” or “Blocked by” function.
* Follow the same branch → PR → review → merge flow.

## Templates

Templates for Issues and Pull Requests are available in the repository to standardise submissions. You can also copy them from the `.github/ISSUE_TEMPLATE` and `.github/PULL_REQUEST_TEMPLATE` directories.