<p align="center">
  <img src="assets/infomagnus-banner.svg" alt="InfoMagnus" height="56" />
</p>

<h1 align="center">🤖 copilot-labs</h1>

<p align="center">
  <img src="https://img.shields.io/badge/GitHub%20Copilot-000000?style=for-the-badge&logo=githubcopilot&logoColor=white" alt="GitHub Copilot" />
  <img src="https://img.shields.io/badge/Hands--on%20Labs-2088FF?style=for-the-badge&logo=readthedocs&logoColor=white" alt="Hands-on Labs" />
  <img src="https://img.shields.io/badge/Level-Fundamentals-4CAF50?style=for-the-badge&logo=bookstack&logoColor=white" alt="Fundamentals" />
</p>

<hr>

## 📚 CP Fundamentals

Start with the language-neutral hands-on labs, then explore the guided demos.

### 🎯 Hands-on Labs

Complete these labs in **any one** of five languages (C++, Python, C#, JavaScript, or Java).
See [cp-fundamentals/labs_fundamental.md](cp-fundamentals/labs_fundamental.md).

| # | Lab | Focus |
|---|---|---|
| 1 | [Ghost text & comment-driven completion](cp-fundamentals/labs_fundamental.md#lab-1--ghost-text--comment-driven-completion) | Ghost text |
| 2 | [Chat modes: Ask · Plan · Edit · Agent (+ inline chat + NES)](cp-fundamentals/labs_fundamental.md#lab-2--chat-modes-ask--plan--edit--agent--inline-chat--nes) | Chat modes |
| 3 | [Writing effective prompts](cp-fundamentals/labs_fundamental.md#lab-3--writing-effective-prompts) | Prompting |
| 4 | [Practical scenarios: generate, refactor, debug, document](cp-fundamentals/labs_fundamental.md#lab-4--practical-scenarios-generate-refactor-debug-document) | Everyday loop |
| 5 | [Introduction to MCP (conceptual)](cp-fundamentals/labs_fundamental.md#lab-5--introduction-to-mcp-conceptual) | MCP concepts |
| 6 | [Responsible usage: review, validate, fix](cp-fundamentals/labs_fundamental.md#lab-6--responsible-usage-review-validate-fix) | Responsible AI |

### 🎬 Demos

Guided walkthroughs with runnable sample code — see [cp-fundamentals/demos/README.md](cp-fundamentals/demos/README.md).

| Demo | Area | Language | Guide |
|---|---|---|---|
| Demo 1 | Copilot overview | Python | [demo-1-copilot-overview](cp-fundamentals/demos/demo-1-copilot-overview/demo.md) |
| Demo 2 | IDE basics | C++ | [demo-2-getting-started](cp-fundamentals/demos/demo-2-getting-started/demo.md) |
| Demo 3 | Prompting | Java | [demo-3-effective-prompts](cp-fundamentals/demos/demo-3-effective-prompts/demo.md) |
| Demo 4 | Tips and techniques | C# → Flutter/Dart | [demo-4-tips-and-techniques](cp-fundamentals/demos/demo-4-tips-and-techniques/demo.md) |

---

## 🌐 Hosted docs site (GitHub Pages)

A participant-facing site (built with the [just-the-docs](https://just-the-docs.com) Jekyll theme)
lives in [`docs/`](docs/). Every demo page embeds its full starter code **inline** — participants
copy, paste, and run with **no clone required** — which scales cleanly to a room of 300+.

**Enable it once (repo admin):**

1. Push to `main`. The workflow [`.github/workflows/pages.yml`](.github/workflows/pages.yml) builds the site.
2. Repo **Settings → Pages → Build and deployment → Source → GitHub Actions**.
3. The site publishes at `https://<owner>.github.io/copilot-labs/`.

**Preview locally:**

```bash
cd docs
bundle install
bundle exec jekyll serve   # http://localhost:4000
```
