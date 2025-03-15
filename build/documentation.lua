

function Update_doc()

  local readme = darwin.candango.Render_text(darwin.dtw.load_file("assets/doc/main"))

  if readme.exist_error then
    print("\n\tERROR candango is: ", readme.error_message)
    os.exit(1)
  end

  print("\n\tREADME renderized")
  darwin.dtw.write_file("README.md", readme.render_text)

end
