project('char-width_freetype', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

freetype_dependency = dependency('freetype2', version: '>=2.10.0')

exe = executable('char_width_freetype', 'char_width_freetype.c',
  install : true,
  dependencies: [freetype_dependency])

test('basic', exe)
