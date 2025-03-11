


local function Compile_code_example(path)
  os.execute("gcc " .. path .. "code.c -o " .. path .. "compiled.out && " .. path .. "compiled.out > " .. path .. "out.txt")
end

function Run_black_box()
  darwin.dtw.write_file("examples/cache", "")
  darwin.dtw.remove_any("examples/cache")

  local dir_path, size = darwin.dtw.list_dirs("examples", true)

  for i=1, size do
    local exist_Ccode = darwin.dtw.load_file(dir_path[i] .. "code.c")
    local out = ""
    if exist_Ccode then
      print("")
      print("\27[33mcompiling: '" .. dir_path[i] .. "'\27[0m\n")
      Compile_code_example(dir_path[i])
      out = darwin.dtw.load_file(dir_path[i] .. "out.txt")
      local color_text = "\27[32m" --GREEN
      if not out then
        color_text = "\27[31m" --RED
      end
      print("\n\t" .. color_text .. "Response:\27[0m")
      print(out)
      print("")
    end
  end
end




