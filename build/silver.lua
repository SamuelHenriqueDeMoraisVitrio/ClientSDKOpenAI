

function Initialize_silver()
  
  darwin.silverchain.generate({
      src = "src",
      tags = { "dep", "includes", "macros","consts", "types", "globals", "dec", "def" },
      project_short_cut = Name_lib
  })

  print("\tFinalized SilverChain.\n")

end



