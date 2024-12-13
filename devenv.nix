{ pkgs, ... }: {
  packages = with pkgs; [
    tree-sitter
    nodePackages.nodejs
    pnpm
    clang_18
    typescript-language-server
    ccls
    just
  ];

  processes = {
    generate.exec = ''
      PATH+=:${pkgs.watchexec}/bin
      watchexec -w grammar.js -- just generate
    '';
  };
}
