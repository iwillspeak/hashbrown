bin_dir = 'bin'

directory bin_dir

test_exe = File.join(bin_dir, 'hash-brown')
cpp_files = FileList['*.cpp']
file test_exe => [ cpp_files, bin_dir] do
  sh %{clang++ --std=c++11 -o #{test_exe} #{cpp_files}}
end

desc "test hash functions"
task :test => test_exe do
  strings = [
   "hello world",
   "foo",
   "the rain in spain falls mainly on the plain",
   ""
  ]

  sh %{#{test_exe.to_s} "#{strings.join '" "'}"}
end

task :default => test_exe
