

function main()

  Name_lib = "SDK_OpenAI"

  arguments = {
    {
      arg="help",
      func=Help,
      description="Describes all building sectors."
    },
    {
      arg="dependencies",
      func=Install_dependencies,
      description="Installs the necessary external dependencies."
    },
    {
      arg="silver",
      func=Initialize_silver,
      description="Implements the necessary imports for 'include' and 'auto complete'."
    },
    {
      arg="document",
      func=Update_doc,
      description="Builds 'README.md' from 'doc/main.md'."
    },
    {
      arg="almaga",
      func=almagamation,
      description="Generate files in realeses"
    }
  }

  Get_args()

  print("\tEND\n\n")
end





