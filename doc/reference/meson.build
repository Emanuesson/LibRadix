
if not meson.version().version_compare('>=0.52.0')
  error('Building documentation requires Meson >= 0.52.0.')
endif
# Check we have the minimum gtk-doc version required. Older versions won't
# generate correct documentation.
dependency('gtk-doc', version : '>=1.32.1',
  fallback : ['gtk-doc', 'dummy_dep'],
  default_options : ['tests=false'])

subdir('xml')

ignore_decorators = [
  'G_GNUC_INTERNAL',
  'G_GNUC_WARN_UNUSED_RESULT',
]

gtkdoc_common_scan_args = [
  '--ignore-decorators=' + '|'.join(ignore_decorators),
]

ignore_headers = [
]

docpath = join_paths(radix_datadir, 'gtk-doc', 'html')
version_conf = configuration_data()
version_conf.set('RADIX_VERSION', meson.project_version())
configure_file(
  input: 'version.xml.in',
  output: 'version.xml',
  configuration: version_conf
)

gnome.gtkdoc('radix',
             main_xml : 'radix-docs.xml',
             namespace : 'g',
             mode : 'none',
             src_dir : [ 'radix' ],
             dependencies : libradix_dep,
             scan_args : gtkdoc_common_scan_args + [
               '--ignore-headers=' + ' '.join(ignore_headers),
             ],
             content_files : [
               'radix-docs.xml',
               'radix-overview.xml',
             ],
             fixxref_args: [
               '--html-dir=' + docpath,
             ],
             install: true,
             check: true)

