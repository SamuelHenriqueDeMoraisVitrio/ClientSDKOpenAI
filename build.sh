
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.out -o darwin && chmod +x darwin

./darwin drop_types
mv darwintypes.lua build

./darwin run_blueprint -mode folder build

