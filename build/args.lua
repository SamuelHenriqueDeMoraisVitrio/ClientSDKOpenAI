

function Get_args()
  for _, obj in ipairs(arguments) do
    if darwin.argv.one_of_args_exist(obj.arg) or darwin.argv.get_total_args_size() == 5 then
      print("\n\t\27[34m" .. obj.arg .. "\27[0m\n")
      obj.func()
    end
  end
  print("")
end



