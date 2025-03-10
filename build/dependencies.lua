



---@param Link table
---@param path string
---@return nil
local function Install_dependencie(Link, path)

  darwin.dtw.remove_any(path .. Link.out)

  local sucesses = os.execute("curl -s -L " .. Link.link .. " -o " .. path .. Link.out) -- Curl -L {link} -o {path_for_dependencie/}{out_renamed}

  if sucesses then
    print("\n\tSuccess in downloading:\n\t" .. Link.out .. "")
    return
  end

  print("\n\tError making request on:\n\t" .. Link.out .. "")

end

local links = {
  {
    link = "https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.000/BearHttpsClientOne.c",
    out = "dep.BearClient.h"
  }
}

---@return nil
function Install_dependencies()


  local path = "src/dependencies/"
  darwin.dtw.remove_any(path)
  local cache = path .. "cache"
  darwin.dtw.write_file(cache, "")
  darwin.dtw.remove_any(cache)

  for I=1, #links do
    Install_dependencie(links[I], path)
  end

  print("\n")

end




