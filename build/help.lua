



function Help()

  for _, obj in ipairs(arguments) do
    print("\n", obj.arg, "\n", obj.description, "\n")
  end

end

