project(
  'LibRadix', 'c',
  version : '0.0.1',
  default_options: [
    'werror=true',
    'warning_level=2',
#    'buildtype=debugoptimized',
    'buildtype=debug',
    'c_std=gnu89',
    'optimization=g',
    'b_ndebug=if-release',
  ]
)

if get_option('buildtype')=='debugoptimized'
  # Even more debugging
  add_project_arguments('-g3', language: 'c')
endif

cc = meson.get_compiler('c')

cdata = configuration_data()

if cc.has_link_argument('-Wl,-Bsymbolic-functions')
  add_project_link_arguments('-Wl,-Bsymbolic-functions', language : 'c')
endif

# Symbol visibility
#if cc.has_argument('-fvisibility=hidden')
#  add_project_arguments('-fvisibility=hidden', language: 'c')
#  export_define = 'extern __attribute__ ((visibility ("default")))'
#else
#  export_define = 'extern'
#endif

# Disable strict aliasing
if cc.has_argument('-fno-strict-aliasing')
  add_project_arguments('-fno-strict-aliasing', language: 'c')
endif

git = find_program('git', required: false)
if git.found()
	git_rev_parse = run_command(git, 'rev-parse', '--short', '@', check: true)
	git_sha = git_rev_parse.stdout().strip()
else
	git_sha = 'unknown'
endif

libradix_version = meson.project_version()
libradix_api_version = '0.9'
version_info = configuration_data()
version_info.set('version', libradix_version)
version_info.set('vcs_tag', git_sha)
libradix_api_version

top_srcdir = include_directories('.')

# Config file
host_system = host_machine.system()
if host_system == 'linux'
  cdata.set_quoted('DEFAULT_OSSPECIFIC_DEF', 'linux')
elif ['darwin', 'ios'].contains(host_system)
  cdata.set_quoted('DEFAULT_OSSPECIFIC_DEF', 'mac')
  # Yes, we set this for iOS too. Same as Autotools.
  cdata.set('HAVE_OSX', 1)
else
  cdata.set_quoted('DEFAULT_OSSPECIFIC_DEF', 'else')
endif
cdata.set('_U_', '')
configure_file(output : 'config.h', configuration : cdata)
configinc = include_directories('.')

pkg = import('pkgconfig')

common_headers = [
  'common_defines.h',
]

glib_dep = [
  dependency('gio-2.0'),
  dependency('gmodule-2.0'),
  dependency('gobject-2.0'),
]

root_inc = include_directories('.')
src_inc = include_directories('radix')

radix_prefix = get_option('prefix')
radix_libdir = join_paths(radix_prefix, get_option('libdir'))
radix_datadir = join_paths(radix_prefix, get_option('datadir'))

gnome = import('gnome')

subdir('radix')

if get_option('test')
	subdir('tests')
endif

if get_option('doc')
	subdir('doc/reference')
endif

