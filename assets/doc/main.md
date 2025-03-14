
\# {Name_lib}
This project is a lightweight and efficient SDK for interacting with OpenAI's API in C

{%
  local path_doc = "assets/doc/"
  local path_examples = "assets/examples"
}

<details>

  <summary><h2>BUILD</h2></summary>


  {darwin.dtw.load_file(path_doc .. "build.md")}

</details>


{darwin.dtw.load_file(path_doc .. "start.md")}

\#\# Examples:

\#\#\# Simple QUestion:

```c
{darwin.dtw.load_file(path_examples .. "/question/main.c")}
```

\#\#\# Calbacks:

```c
{darwin.dtw.load_file(path_examples .. "/callback/main.c")}
```

