# vs code lint配置

VS Code 使用 markdownlint 插件来进行 Markdown 文件的 lint 检查。以下是修改 lint 规则的方法：

1. 在项目根目录下创建一个 `.markdownlint.json` 文件来配置规则。我来帮你创建这个文件:

    Made changes.

    这个示例配置文件中:

    - `"MD013": false` - 关闭行长度限制
    - `"MD033": false` - 允许使用内联 HTML
    - `"MD041": false` - 不要求文件开头必须是一级标题
    - `"MD047": false` - 不要求文件必须以新行结尾
    - `"no-hard-tabs": false` - 允许使用制表符

2. 你也可以通过 VS Code 的用户设置来全局配置 markdownlint 规则:

    - 打开命令面板 (Cmd+Shift+P 或 Ctrl+Shift+P)
    - 输入 "Preferences: Open Settings (JSON)"
    - 在 settings.json 中添加 markdownlint 配置，例如:

        ```json
        {
        "markdownlint.config": {
            "MD013": false,
            "MD033": false
        }
        }
        ```

3. 如果想要禁用某个文件中的特定规则，可以在 Markdown 文件中使用注释:

    ```markdown
    <!-- markdownlint-disable MD013 -->
    这一行可以很长...
    <!-- markdownlint-enable MD013 -->
    ```

---

常用的 markdownlint 规则包括：

- `MD001` - 标题层级顺序
- `MD009` - 行尾空格
- `MD013` - 行长度限制
- `MD033` - 内联 HTML 使用限制
- `MD041` - 文件首行必须是标题
- `MD047` - 文件末尾必须有空行

你可以根据需要启用或禁用这些规则。完整的规则列表可以在 markdownlint 的官方文档中找到。

需要注意的是，你可能需要安装 markdownlint 插件才能使这些设置生效。如果你还没有安装，VS Code 会自动提示你安装。
