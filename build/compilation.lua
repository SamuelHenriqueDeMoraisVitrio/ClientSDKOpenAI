


local function Preparation(cc, main, flags, path_out, name_out)
  darwin.dtw.remove_any(path_out)
  local path_out = path_out .. "/"
  darwin.dtw.write_file(path_out .. "cache", "")
  darwin.dtw.remove_any(path_out .. "cache")

  local result = os.execute(cc .. ' ' .. flags .. " -o " .. path_out .. name_out .. " src/" .. main)

  if not result then
    os.exit(1)
  end

  print("\n\tCompiled the" .. name_out .. " in " .. path_out .. "\n")
end

function Comp_testing()
  Preparation("gcc", "testing.c ", "", "test/c", "test.out")
  os.execute("test/c/test.out > test/c/teste.txt")
end

function Comp()
  Preparation("gcc", "main.c", "", "realeses/" .. Name_lib, Name_lib)

  darwin.dtw.remove_any("realeses/" .. Name_lib .. ".zip")
  os.execute("zip -r realeses/" .. Name_lib .. ".zip realeses/" .. Name_lib)
end



