foreach t: [
  'test-radix-network.c',
  'test-radix-tree.c',
]

  exe = executable(t, t,
    pie: true,
    install: false,
    include_directories: [root_inc, src_inc],
    dependencies: [ libradix_dep ],
  )

  test(t, exe, workdir: meson.current_build_dir())
endforeach

