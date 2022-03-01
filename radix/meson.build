public_headers = [
  'radix-network.h',
  'radix-tree.h',
]

sources = [
  'radix-network.c',
  'radix-tree.c',
]

libradix = library('libradix', sources + public_headers,
  version : '0.1.0',
  soversion : '0',
  include_directories : [
    configinc,      # Because of config.h
    top_srcdir,     # Because of common_defines.h
  ],
  dependencies : glib_dep ,
  install : false,
)

install_headers(public_headers)

radix_pkgconfigreldir = join_paths(radix_libdir, 'pkgconfig')

pkg.generate(libradix,
  requires : ['glib-2.0', 'gobject-2.0'],
  version : libradix_version,
  install_dir : radix_pkgconfigreldir,
  filebase : 'libradix',
  name : 'LibRadix',
  description : 'Glib-based Radix tree non-recursive implementation',
)

libradix_dep = declare_dependency(
              sources: public_headers,
         dependencies: glib_dep,
            link_with: libradix,
  include_directories: include_directories('.'),
)


