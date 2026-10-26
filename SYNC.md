# 跨电脑访问与对话接续

更新：2026-10-26。

## 仓库

- GitHub 账号：FrankZH-1
- 仓库：https://github.com/FrankZH-1/Motion-Control
- HTTPS 克隆地址：https://github.com/FrankZH-1/Motion-Control.git

仓库地址是访问入口，不是身份凭证。如果仓库为私有，另一台电脑需要登录有权限的 GitHub 账号。

## 另一台电脑获取文件

安装 Git 后，可使用 GitHub Desktop 登录并克隆仓库；也可使用以下命令：

```sh
git clone https://github.com/FrankZH-1/Motion-Control.git
cd Motion-Control
```

私有仓库需要先完成认证。安装 GitHub CLI 后可执行 `gh auth login --hostname github.com --git-protocol https --web`，使用自己的浏览器完成登录，然后执行 `gh auth setup-git`。不要把账号密码、访问令牌或 SSH 私钥提交到仓库或粘贴到对话中。

如果使用 SSH，应在新电脑上创建并配置它自己的 SSH 密钥，而不是把本机私钥复制到项目中。现有插件授权不能作为可转移到另一台电脑的登录凭证导出。

在 Codex 中打开克隆后的文件夹，首先阅读 PROJECT.md 和 CONTEXT.md。构建方式见 README.md；build/ 不同步，需在每台电脑重新构建。

## 日常同步

开始工作前，在工作区没有未提交修改时运行：

```sh
git pull --ff-only
```

结束工作时，先查看并选择需要同步的文件：

```sh
git status
git add README.md PROJECT.md CONTEXT.md SYNC.md CMakeLists.txt src .gitignore
git commit -m "Update motion control project"
git push
```

以后增加新目录时应明确选择并加入。没有变化时不需要 commit。若存在本地修改或分叉，不要强制覆盖；先保存自己的修改，再合并处理。GitHub 不会自动监控本地文件夹；只有提交并推送的版本才会到远端。

## Codex 对话记录与文件同步的区别

Git 同步项目文件及其提交历史，不会自动同步 Codex 的原生聊天记录、工具调用和应用设置。本仓库的 CONTEXT.md 是可携带的工作摘要，不是完整对话导出。

官方文档提供两种相关能力，是否可用取决于客户端、账号及工作区设置：

1. 远程连接：在支持的桌面客户端 Settings → Connections 中连接原电脑，可访问该主机上的项目和聊天；原电脑需要在线，应用保持运行。
2. 主机间 Handoff：先连接目标主机，并在目标主机保存同一 Git 仓库对应的项目；再在聊天运行位置选择目标并交接，迁移聊天与 Git 状态。这是显式交接，不是克隆仓库自动带走聊天。

Work 云端对话同步与 Codex 历史也不应混为一谈。官方文档明确：对话同步不会上传整个本地文件夹，Work 对话历史与 Codex 历史分开；既有本地任务不能仅因登录同一账号就假定已变成云端任务。

本项目最稳妥的接续方式是：克隆仓库 → 在新电脑打开项目 → 让新的聊天读取 CONTEXT.md 和 PROJECT.md。若必须继续原生同一聊天，再检查远程连接或 Handoff 是否可用。

来源（2026-10-26 查阅）：

- [OpenAI 官方：Remote connections](https://learn.chatgpt.com/docs/remote-connections)
- [OpenAI 官方：Projects and chats](https://learn.chatgpt.com/docs/projects)
