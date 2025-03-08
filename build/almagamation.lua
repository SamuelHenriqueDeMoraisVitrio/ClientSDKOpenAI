

local max_content = darwin.camalgamator.ONE_MB * 10
local max_recursion = 100

local function almagamation_write(file_path)
  result = darwin.camalgamator.generate_amalgamation_with_callback(file_path,
    function(import, path)
      if string.find(path, "dependencies") then
        print("\n\tIgnored " .. path .. " include")
        return "dont-include"
      end
      return "include-once"
    end,
    max_content,
    max_recursion
  )

  return result
end

function almagamation()

  local one = almagamation_write("src/one.c")
  local def = almagamation_write("src/imports/imports.def.h")
  local dec = almagamation_write("src/imports/imports.dec.h")

  local path = "realeses/" .. Name_lib .. "/" .. Name_lib
  darwin.dtw.remove_any("realeses/" .. Name_lib)
  darwin.dtw.write_file(path .. "One.c", one)
  darwin.dtw.write_file(path .. ".h", dec)
  darwin.dtw.write_file(path .. ".c", def)

  print("\n\tGenerate files in realeses\n")
end



