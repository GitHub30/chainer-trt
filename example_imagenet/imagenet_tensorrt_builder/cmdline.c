/*
  File autogenerated by gengetopt version 2.22.6
  generated with the following command:
  gengetopt 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "";

const char *gengetopt_args_info_usage = "Usage: imagenet_tensorrt_builder [OPTIONS]...";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                  Print help and exit",
  "  -V, --version               Print version and exit",
  "  -i, --dir=filename          path to directory name contains model json and\n                                weights exported by dump_chainer.py or\n                                dump_caffe.py",
  "  -g, --gpu=INT               GPU ID  (default=`0')",
  "  -o, --model=filename        specify where to save the built model",
  "  -m, --mode=STRING           specify mode  (possible values=\"fp32\",\n                                \"fp16\", \"int8\" default=`fp32')",
  "  -c, --calib=filename        specify filename of calibration image list if\n                                using mode=int8 and do calibration from scratch",
  "      --in-cache=filename     specify filename to calibration cache when using\n                                mode=int8",
  "      --out-cache=filename    specify output filename to calibration cache if\n                                using mode=int8 (--calib also needs to be\n                                specified)  (default=`')",
  "  -b, --max-batch=batch-size  specify the maximum batch size this model is\n                                supposed to receive  (default=`1')",
  "  -w, --workspace=GB          specify workspace size in GB that TensorRT is\n                                allowed to use while building the network\n                                (default=`4')",
  "  -v, --verbose               Verbose mode",
    0
};

typedef enum {ARG_NO
  , ARG_STRING
  , ARG_INT
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);

static int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error);

const char *cmdline_parser_mode_values[] = {"fp32", "fp16", "int8", 0}; /*< Possible values for mode. */

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->dir_given = 0 ;
  args_info->gpu_given = 0 ;
  args_info->model_given = 0 ;
  args_info->mode_given = 0 ;
  args_info->calib_given = 0 ;
  args_info->in_cache_given = 0 ;
  args_info->out_cache_given = 0 ;
  args_info->max_batch_given = 0 ;
  args_info->workspace_given = 0 ;
  args_info->verbose_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->dir_arg = NULL;
  args_info->dir_orig = NULL;
  args_info->gpu_arg = 0;
  args_info->gpu_orig = NULL;
  args_info->model_arg = NULL;
  args_info->model_orig = NULL;
  args_info->mode_arg = gengetopt_strdup ("fp32");
  args_info->mode_orig = NULL;
  args_info->calib_arg = NULL;
  args_info->calib_orig = NULL;
  args_info->in_cache_arg = NULL;
  args_info->in_cache_orig = NULL;
  args_info->out_cache_arg = gengetopt_strdup ("");
  args_info->out_cache_orig = NULL;
  args_info->max_batch_arg = 1;
  args_info->max_batch_orig = NULL;
  args_info->workspace_arg = 4;
  args_info->workspace_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->dir_help = gengetopt_args_info_help[2] ;
  args_info->gpu_help = gengetopt_args_info_help[3] ;
  args_info->model_help = gengetopt_args_info_help[4] ;
  args_info->mode_help = gengetopt_args_info_help[5] ;
  args_info->calib_help = gengetopt_args_info_help[6] ;
  args_info->in_cache_help = gengetopt_args_info_help[7] ;
  args_info->out_cache_help = gengetopt_args_info_help[8] ;
  args_info->max_batch_help = gengetopt_args_info_help[9] ;
  args_info->workspace_help = gengetopt_args_info_help[10] ;
  args_info->verbose_help = gengetopt_args_info_help[11] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{

  free_string_field (&(args_info->dir_arg));
  free_string_field (&(args_info->dir_orig));
  free_string_field (&(args_info->gpu_orig));
  free_string_field (&(args_info->model_arg));
  free_string_field (&(args_info->model_orig));
  free_string_field (&(args_info->mode_arg));
  free_string_field (&(args_info->mode_orig));
  free_string_field (&(args_info->calib_arg));
  free_string_field (&(args_info->calib_orig));
  free_string_field (&(args_info->in_cache_arg));
  free_string_field (&(args_info->in_cache_orig));
  free_string_field (&(args_info->out_cache_arg));
  free_string_field (&(args_info->out_cache_orig));
  free_string_field (&(args_info->max_batch_orig));
  free_string_field (&(args_info->workspace_orig));
  
  

  clear_given (args_info);
}

/**
 * @param val the value to check
 * @param values the possible values
 * @return the index of the matched value:
 * -1 if no value matched,
 * -2 if more than one value has matched
 */
static int
check_possible_values(const char *val, const char *values[])
{
  int i, found, last;
  size_t len;

  if (!val)   /* otherwise strlen() crashes below */
    return -1; /* -1 means no argument for the option */

  found = last = 0;

  for (i = 0, len = strlen(val); values[i]; ++i)
    {
      if (strncmp(val, values[i], len) == 0)
        {
          ++found;
          last = i;
          if (strlen(values[i]) == len)
            return i; /* exact macth no need to check more */
        }
    }

  if (found == 1) /* one match: OK */
    return last;

  return (found ? -2 : -1); /* return many values or none matched */
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  int found = -1;
  if (arg) {
    if (values) {
      found = check_possible_values(arg, values);      
    }
    if (found >= 0)
      fprintf(outfile, "%s=\"%s\" # %s\n", opt, arg, values[found]);
    else
      fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->dir_given)
    write_into_file(outfile, "dir", args_info->dir_orig, 0);
  if (args_info->gpu_given)
    write_into_file(outfile, "gpu", args_info->gpu_orig, 0);
  if (args_info->model_given)
    write_into_file(outfile, "model", args_info->model_orig, 0);
  if (args_info->mode_given)
    write_into_file(outfile, "mode", args_info->mode_orig, cmdline_parser_mode_values);
  if (args_info->calib_given)
    write_into_file(outfile, "calib", args_info->calib_orig, 0);
  if (args_info->in_cache_given)
    write_into_file(outfile, "in-cache", args_info->in_cache_orig, 0);
  if (args_info->out_cache_given)
    write_into_file(outfile, "out-cache", args_info->out_cache_orig, 0);
  if (args_info->max_batch_given)
    write_into_file(outfile, "max-batch", args_info->max_batch_orig, 0);
  if (args_info->workspace_given)
    write_into_file(outfile, "workspace", args_info->workspace_orig, 0);
  if (args_info->verbose_given)
    write_into_file(outfile, "verbose", 0, 0 );
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cmdline_parser_required2(args_info, prog_name, 0) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error)
{
  int error_occurred = 0;
  FIX_UNUSED (additional_error);

  /* checks for required options */
  if (! args_info->dir_given)
    {
      fprintf (stderr, "%s: '--dir' ('-i') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (! args_info->model_given)
    {
      fprintf (stderr, "%s: '--model' ('-o') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  
  /* checks for dependences among options */

  return error_occurred;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  if (possible_values && (found = check_possible_values((value ? value : default_value), possible_values)) < 0)
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s' (`-%c')%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt, short_opt,
          (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s'%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt,
          (additional_error ? additional_error : ""));
      return 1; /* failure */
    }
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_INT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "dir",	1, NULL, 'i' },
        { "gpu",	1, NULL, 'g' },
        { "model",	1, NULL, 'o' },
        { "mode",	1, NULL, 'm' },
        { "calib",	1, NULL, 'c' },
        { "in-cache",	1, NULL, 0 },
        { "out-cache",	1, NULL, 0 },
        { "max-batch",	1, NULL, 'b' },
        { "workspace",	1, NULL, 'w' },
        { "verbose",	0, NULL, 'v' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVi:g:o:m:c:b:w:v", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'i':	/* path to directory name contains model json and weights exported by dump_chainer.py or dump_caffe.py.  */
        
        
          if (update_arg( (void *)&(args_info->dir_arg), 
               &(args_info->dir_orig), &(args_info->dir_given),
              &(local_args_info.dir_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "dir", 'i',
              additional_error))
            goto failure;
        
          break;
        case 'g':	/* GPU ID.  */
        
        
          if (update_arg( (void *)&(args_info->gpu_arg), 
               &(args_info->gpu_orig), &(args_info->gpu_given),
              &(local_args_info.gpu_given), optarg, 0, "0", ARG_INT,
              check_ambiguity, override, 0, 0,
              "gpu", 'g',
              additional_error))
            goto failure;
        
          break;
        case 'o':	/* specify where to save the built model.  */
        
        
          if (update_arg( (void *)&(args_info->model_arg), 
               &(args_info->model_orig), &(args_info->model_given),
              &(local_args_info.model_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "model", 'o',
              additional_error))
            goto failure;
        
          break;
        case 'm':	/* specify mode.  */
        
        
          if (update_arg( (void *)&(args_info->mode_arg), 
               &(args_info->mode_orig), &(args_info->mode_given),
              &(local_args_info.mode_given), optarg, cmdline_parser_mode_values, "fp32", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "mode", 'm',
              additional_error))
            goto failure;
        
          break;
        case 'c':	/* specify filename of calibration image list if using mode=int8 and do calibration from scratch.  */
        
        
          if (update_arg( (void *)&(args_info->calib_arg), 
               &(args_info->calib_orig), &(args_info->calib_given),
              &(local_args_info.calib_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "calib", 'c',
              additional_error))
            goto failure;
        
          break;
        case 'b':	/* specify the maximum batch size this model is supposed to receive.  */
        
        
          if (update_arg( (void *)&(args_info->max_batch_arg), 
               &(args_info->max_batch_orig), &(args_info->max_batch_given),
              &(local_args_info.max_batch_given), optarg, 0, "1", ARG_INT,
              check_ambiguity, override, 0, 0,
              "max-batch", 'b',
              additional_error))
            goto failure;
        
          break;
        case 'w':	/* specify workspace size in GB that TensorRT is allowed to use while building the network.  */
        
        
          if (update_arg( (void *)&(args_info->workspace_arg), 
               &(args_info->workspace_orig), &(args_info->workspace_given),
              &(local_args_info.workspace_given), optarg, 0, "4", ARG_INT,
              check_ambiguity, override, 0, 0,
              "workspace", 'w',
              additional_error))
            goto failure;
        
          break;
        case 'v':	/* Verbose mode.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->verbose_given),
              &(local_args_info.verbose_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "verbose", 'v',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          /* specify filename to calibration cache when using mode=int8.  */
          if (strcmp (long_options[option_index].name, "in-cache") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->in_cache_arg), 
                 &(args_info->in_cache_orig), &(args_info->in_cache_given),
                &(local_args_info.in_cache_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "in-cache", '-',
                additional_error))
              goto failure;
          
          }
          /* specify output filename to calibration cache if using mode=int8 (--calib also needs to be specified).  */
          else if (strcmp (long_options[option_index].name, "out-cache") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->out_cache_arg), 
                 &(args_info->out_cache_orig), &(args_info->out_cache_given),
                &(local_args_info.out_cache_given), optarg, 0, "", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "out-cache", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (check_required)
    {
      error_occurred += cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
