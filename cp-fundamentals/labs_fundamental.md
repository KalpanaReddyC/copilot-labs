<p align="center">
  <img src="../assets/infomagnus-banner.svg" alt="InfoMagnus" height="56" />
</p>

<h1 align="center">🎯 GitHub Copilot — Common Hands-on Labs</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white" alt="Python" />
  <img src="https://img.shields.io/badge/C%23-239120?style=for-the-badge&logo=csharp&logoColor=white" alt="C#" />
  <img src="https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black" alt="JavaScript" />
  <img src="https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white" alt="Java" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/GitHub%20Copilot-000000?style=for-the-badge&logo=githubcopilot&logoColor=white" alt="GitHub Copilot" />
  <img src="https://img.shields.io/badge/Hands--on-Labs-2088FF?style=for-the-badge" alt="Hands-on Labs" />
</p>

<hr>

A single set of **language-neutral** labs you can complete in **any one** of five languages:
**C++, Python, C#, JavaScript, or Java**. Every task is described by *intent* — you tell GitHub
Copilot what you want and it generates the code in the language you picked. There are no
per-language starter files to maintain: **Copilot writes the code, you review and verify it.**

> Use this guide when a room has mixed language preferences. Each participant picks their own
> language, follows the exact same steps, and ends with a working, verified program.

---

## How to use these labs

1. **Pick one language** and do the [Shared setup](#shared-setup-do-once) once.
2. Work through the labs **in order** — each builds a skill the next one uses.
3. For every step, the guide gives you the **exact prompt to type** and **which Copilot mode**
   to use (ghost text, inline chat, Ask / Plan / Edit / Agent, or Next Edit Suggestions).
4. **Try it yourself first**, then read what Copilot produced before accepting it.
5. **Run & verify** at the end of each lab — the program must print all `PASS` lines.

Budget: ~5 min setup + ~20 min per lab. Do as many as time allows; Labs 1–4 are the core.

---

## Shared setup (do once)

You need an editor with Copilot, a GitHub Copilot licence, and **one** language toolchain.

### Editor + Copilot (any one editor)

| Requirement | Check it works |
|---|---|
| **VS Code** (recommended), **Visual Studio 2022**, or a **JetBrains IDE** | Editor opens |
| **GitHub Copilot** + **GitHub Copilot Chat** extensions, signed in | Copilot status bar shows **Ready** |
| GitHub account with an active **Copilot licence** | No "no access" warning in the Copilot panel |

Supported IDEs and per-IDE features: the
[Copilot feature matrix](https://docs.github.com/en/copilot/reference/copilot-feature-matrix).

### Pick ONE language toolchain

Install the toolchain for the language you'll use, plus its editor extension. **Any of the five
is fully supported** — pick what you know best.

| Language | Install (on PATH) | Verify | Editor extension |
|---|---|---|---|
| **C++** | C++17 compiler — `g++`, `clang++`, or MSVC `cl` | `g++ --version` | C/C++ (ms-vscode.cpptools) |
| **Python** | **Python 3.10+** | `python --version` | Python (ms-python.python) |
| **C#** | **.NET SDK 8.0+ (LTS)** | `dotnet --version` | C# Dev Kit (ms-dotnettools.csdevkit) |
| **JavaScript** | **Node.js LTS** + npm | `node -v` && `npm -v` | (built-in JS support) |
| **Java** | **JDK 17+** | `java -version` && `javac -version` | Extension Pack for Java (vscjava.vscode-java-pack) |

> No paid services, servers, or network calls are required — everything runs locally.

### Create & run a scratch project (your language)

Use this to create the file(s) each lab asks for, and to run them.

**C++**
```bash
# create main.cpp, then:
g++ -std=c++17 main.cpp -o app && ./app        # bash
g++ -std=c++17 .\main.cpp -o app.exe; .\app.exe # PowerShell
```

**Python**
```bash
# create main.py, then:
python main.py
```

**C#**
```bash
dotnet new console -o lab
cd lab
# edit Program.cs, then:
dotnet run
```

**JavaScript**
```bash
# create main.js, then:
node main.js
```

**Java**
```bash
# create Main.java, then:
javac Main.java
java Main
```

### Copilot features you'll use (cheat sheet)

| Feature | What it is | How to invoke |
|---|---|---|
| **Ghost text** | Grey inline completion as you type | Just type; **Tab** accepts, **Esc** dismisses |
| **Cycle suggestions** | Alternative completions | **Alt+]** / **Alt+[** |
| **Inline chat** | Ask/edit inside the file | **Ctrl+I** (VS Code) |
| **Ask mode** | Explain code, answer questions (no edits) | Chat view → **Ask** |
| **Plan mode** | Outline steps before making changes | Chat view → **Plan** |
| **Edit mode** | Targeted edits with a reviewable diff | Chat view → **Edit** |
| **Agent mode** | Multi-file, multi-step tasks | Chat view → **Agent** |
| **Next Edit Suggestions (NES)** | Predicts your *next* edit | Enable in settings; **Tab** to jump/accept |

> **Enable NES in VS Code:** Settings → search `github.copilot.nextEditSuggestions.enabled` → **on**.

---

## Lab 1 — Ghost text & comment-driven completion

**Time:** ~15 min

**# Learning objectives**
- Describe intent in a comment and let Copilot's ghost text write the function body.
- Compare alternative completions and accept the best one with confidence.

**Mode:** ghost text
**Model:** base model (e.g. GPT-5.4)

**Prompt to give:**
> `// TODO: validate that a string is a well-formed email address -> returns true/false`
> `// TODO: check a password is strong (>= 8 chars, upper, lower, digit) -> true/false`

1. Create the scratch file for your language (see setup) and add two `TODO` comments:
   - `// TODO: validate that a string is a well-formed email address -> returns true/false`
   - `// TODO: check a password is strong (>= 8 chars, upper, lower, digit) -> true/false`
2. Put your cursor under the first comment and start typing the function signature. Watch for
   **grey ghost text**. Press **Alt+]** to compare an alternative, then **Tab** to accept.
   *Do not type the regex yourself* — let Copilot suggest it, then read it before accepting.
3. Repeat for the password check.
4. Below them, let ghost text help you write a few print/assert checks that exercise a valid and
   an invalid input for each function.
5. **Run & verify** — all checks print `PASS`.

**Language note:** name functions idiomatically — `validate_email` / `is_strong_password`
(Python), `validateEmail` / `isStrongPassword` (C++, C#, JavaScript, Java). Copilot adapts to the file's
language automatically.

**Checkpoints**
- ✅ You saw ghost text and accepted a suggestion with **Tab**.
- ✅ Both functions were generated from comments, not hand-typed.
- ✅ The program runs and prints only `PASS`.

**Stretch:** add a `validate_phone` helper from a comment; use **Alt+]** to compare two regexes.

---

## Lab 2 — Chat modes: Ask · Plan · Edit · Agent (+ inline chat + NES)

**Time:** ~25 min

**# Learning objectives**
- Grow a small module using the right Copilot mode at each step.
- Know when to use ghost text, inline chat, Ask, Edit, Agent, and NES.

**Mode:** ghost text · inline chat · Ask · Plan · Edit · Agent · NES
**Model:** base model (e.g. GPT-5.4)

**Prompt to give:**
> `Build a math utilities module (factorial, gcd, average/mean). Validate negative input,`
> `explain gcd's complexity, refactor average to handle empty input, then add unit tests.`

1. **Ghost text — `factorial`.** New file. Type a `factorial` signature and let ghost text
   complete it. Compare an alternative with **Alt+]**, then accept.
2. **Inline chat — validate input.** Cursor inside `factorial`, press **Ctrl+I**:
   > `Return/throw a clear error if n is negative`
   Review the diff and accept.
3. **Ask mode — understand code.** Add a `gcd` function (ghost text). Open Chat → **Ask**, select
   it, and ask:
   > `Explain how this works and its time complexity`
   You get an explanation with **no file change** (Ask never edits).
4. **Edit mode — refactor safely.** Add an `average`/`mean` function. Chat → **Edit**, select it:
   > `Refactor to handle an empty input safely and add a doc comment`
   Review and apply the diff.
5. **NES — propagate a rename.** Rename `average` to `mean` at its definition. Copilot shows a
   **Next Edit Suggestion** at the call site — press **Tab** to jump, **Tab** to accept.
6. **Agent mode — multi-step.** Chat → **Agent**:
   > `Add unit tests for all functions in this file and a short README section explaining them`
   Review each proposed change before accepting.
7. **Run & verify.**

**Picking a mode:** Ask = "explain / what is", Plan = "outline approach before edits", Edit =
"change this selection", Agent = "do a multi-step task". Use the smallest mode that fits.

**Checkpoints**
- ✅ `factorial` came from ghost text and rejects negative input.
- ✅ Ask explained `gcd` **without** editing the file.
- ✅ Edit added empty-input handling via a reviewed diff.
- ✅ NES finished the rename at the call site.
- ✅ Agent added tests you reviewed before accepting.

---

## Lab 3 — Writing effective prompts

**Time:** ~20 min

**# Learning objectives**
- Feel the difference between weak and strong prompts on the same task.
- Steer Copilot with context variables (`#file`, `@workspace`).

**Mode:** Chat (Ask / Plan / Edit) with context variables
**Model:** base model (e.g. GPT-5.4)

1. Create a small list/array of "user" records, each with a `name`, `age`, and `active` flag
   (let ghost text build the sample data).
2. **Weak prompt.** In Chat → Edit, select the data and ask:
   > `sort this`
   Note how much Copilot has to guess.
3. **Strong prompt.** Undo, then ask precisely.
   **Prompt to give:**
   > `Sort the users by active first (active before inactive), then by age ascending, then by
   > name A–Z. Do not mutate the original; return a new sorted collection.`
   Compare the result — specificity wins.
4. **Add context.** Use context variables so Copilot sees the right scope:
   - VS Code Chat: reference the current file with `#` (e.g. `#<filename>`) or the workspace with
     `@workspace`, then ask a question that depends on that file.
   Observe how referencing context improves the answer.
5. **Run & verify** the sort output is correct for a tie on age.

**Checkpoints**
- ✅ You produced a multi-key sort from a single precise prompt.
- ✅ The original collection is unchanged (immutability respected).
- ✅ You used at least one context reference (`#file` or `@workspace`).

**Stretch:** ask Copilot to add a secondary prompt that groups users by `active` and counts each.

---

## Lab 4 — Practical scenarios: generate, refactor, debug, document

**Time:** ~25 min

**# Learning objectives**
- Run the everyday loop: generate, refactor, debug, and document code with Copilot.
- Use Ask mode to find the root cause of a real bug.

**Mode:** Ask · Edit · inline chat
**Model:** base model (e.g. GPT-5.4)

**Prompt to give:**
> `Create a function that parses a "key=value" config string into a map/dictionary/object,`
> `ignoring blank lines and lines starting with #. Then help me debug, refactor, and document it.`

1. **Generate.** Ask Copilot (Edit mode) to create a function that parses a `"key=value"` config
   string into a map/dictionary/object, ignoring blank lines and lines starting with `#`.
2. **Introduce a bug on purpose.** By hand, change the split to only keep the first character of
   the value (e.g. slice/substr wrong). Run it — a test now fails.
3. **Debug with Copilot.** Select the failing function, Chat → **Ask**:
   > `This returns the wrong value for keys whose value has more than one character. Why, and
   > what's the fix?`
   Apply the fix via **Edit** and re-run.
4. **Refactor.** Inline chat (**Ctrl+I**):
   > `Refactor for readability and handle a missing '=' gracefully`
5. **Document.** Ask Copilot to add a doc comment describing parameters, return value, and edge
   cases.
6. **Run & verify** — all checks pass, including a multi-character value and a `#comment` line.

**Checkpoints**
- ✅ Copilot generated a working parser.
- ✅ You used Ask mode to locate the root cause of a real bug.
- ✅ The refactor handles a malformed line without crashing.
- ✅ A clear doc comment now describes the function.

---

## Lab 5 — Introduction to MCP (conceptual)

**Time:** ~20 min

**# Learning objectives**
- Explain what the Model Context Protocol (MCP) is in your own words.
- Simulate a tool registry and dispatcher locally, with no servers.

**Mode:** Ask · Agent
**Model:** reasoning model (e.g. Claude Sonnet 4 / GPT-5 mini)

**Prompt to give:**
> `In 5 bullet points, what is MCP (Model Context Protocol), and how do MCP servers give an`
> `AI agent access to tools and data? Keep it tool-agnostic.`

1. **Learn.** Chat → **Ask**:
   > `In 5 bullet points, what is MCP (Model Context Protocol), and how do MCP servers give an
   > AI agent access to tools and data? Keep it tool-agnostic.`
2. **Model a registry.** Create a small data structure that lists three imaginary "tools", each
   with a `name`, `description`, and `input` schema (let ghost text build it).
3. **Write a dispatcher.** Ask Copilot to write a function that, given a tool name and an input,
   looks up the tool and returns a simulated result — mirroring how an MCP client would route a
   call to an MCP server.
4. **Agent step.** Chat → **Agent**:
   > `Add a new "weather" tool to the registry and a test that dispatches a call to it`
   Review before accepting.
5. **Discuss (no code):** ask Copilot when a *real* MCP server would be preferable to hard-coding
   a tool, and what security questions to ask before enabling one.

**Checkpoints**
- ✅ You can explain MCP in your own words (client, server, tools, context).
- ✅ Your dispatcher routes a named call to the right simulated tool.
- ✅ Agent extended the registry and you reviewed the change.

---

## Lab 6 — Responsible usage: review, validate, fix

**Time:** ~20 min

**# Learning objectives**
- Treat Copilot output as a draft: review critically, validate with tests, and fix.
- Catch a subtle boundary/operator bug that only review or tests reveal.

**Mode:** Ask · Edit
**Model:** reasoning model (e.g. Claude Sonnet 4 / GPT-5 mini)

**Prompt to give:**
> `Review this for boundary bugs, wrong comparison operators, and unhandled negative or zero`
> `input. List issues before changing anything, then add boundary tests and fix.`

1. Ask Copilot (Edit) to generate a function that returns a discount percentage for an order
   total (e.g. tiers at 100 / 500 / 1000). Accept its first suggestion **as-is**.
2. **Review critically.** Chat → **Ask**:
   > `Review this for boundary bugs, wrong comparison operators, and unhandled negative or zero
   > input. List issues before changing anything.`
3. **Validate with tests.** Ask Copilot to add tests for the **boundaries** (exactly 100, 500,
   1000) and for negative/zero input. Run them — expect at least one failure.
4. **Fix.** Use **Edit** to correct the boundary/operator bug and handle invalid input.
5. **Re-run** until all tests pass.
6. **Reflect:** note one thing Copilot got wrong that you only caught by reviewing.

**Responsible-usage reminders**
- **Review everything** Copilot generates — it can produce subtle bugs and outdated patterns.
  You own the code you accept.
- **Never paste secrets, credentials, or PII** into prompts.
- **Test generated code** and check edge cases before trusting it.
- **Review before committing.** Copilot is a fast pair programmer, not an authority.

**Checkpoints**
- ✅ You found at least one real issue by reviewing, not running.
- ✅ Boundary tests exist and pass after your fix.
- ✅ Invalid input is handled safely.

---

## Wrap-up

You practised the full Copilot workflow — ghost text, inline chat, Ask / Plan / Edit / Agent, NES,
effective prompting, MCP concepts, and responsible review — **in your own language**. The same
habits carry over to the Intermediate, Prompt Engineering, Advanced, and Agents & MCP sessions.
